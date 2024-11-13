export module ColorCpp:InternalUtil;
import :Math;
import :RGB;
import :Type;
import <tuple>;

export namespace colorcpp
{
    class InternalUtil
    {
    public:
        template<class HS>
        [[nodiscard]] constexpr static double DiffHueSaturation(const HS& a, const HS& b)
        {
            const double ah = RepeatHue360(a.h);
            const double bh = RepeatHue360(b.h);
            const double dH = Math::SinDeg(((bh - ah + 360) / 2));
            return 2 * Math::Sqrt(a.s * b.s) * dH;
        }
        template<class HC>
        [[nodiscard]] constexpr static double DiffHueChroma(const HC& a, const HC& b)
        {
            const double ah = RepeatHue360(a.h);
            const double bh = RepeatHue360(b.h);
            const double dH = Math::SinDeg(((bh - ah + 360) / 2));
            return 2 * Math::Sqrt(a.c * b.c) * dH;
        }
        [[nodiscard]] constexpr static double DiffHue(double a, double b)
        {
            const double ah = RepeatHue360(a);
            const double bh = RepeatHue360(b);
            if (Math::Abs(bh - ah) > 180) {
                return ah - (bh - 360 * Math::Sign(bh - ah));
            } else {
                return bh - ah;
            }
        }
        template<class RGBType>
        [[nodiscard]] constexpr static double DiffRGB(const RGBType& a, const RGBType& b)
        {
            const RGBType diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }

        template<class LabType>
        [[nodiscard]] constexpr static double DiffLab(const LabType& a, const LabType& b)
        {
            const LabType diff = a - b;
            return Math::Sqrt(
                diff.l * diff.l +
                diff.a * diff.a +
                diff.b * diff.b
            );
        }
        template<class LCHType>
        [[nodiscard]] constexpr static double DiffLCH(const LCHType& a, const LCHType& b)
        {
            const double l = a.l - b.l;
            const double c = a.c - b.c;
            const double h = DiffHueChroma(a, b);
            return Math::Sqrt(
                l * l
                + c * c
                + h * h
            );
        }

        [[nodiscard]] static constexpr double RepeatHue360(double h) noexcept
        {
            return Math::Repeat(h, 360.0);
        }
        [[nodiscard]] static constexpr std::tuple<double, double, double> HueMaxMin(const RGB& rgb) noexcept
        {
            return HueMaxMin(rgb.r, rgb.g, rgb.b);
        }
        [[nodiscard]] static constexpr std::tuple<double, double, double> HueMaxMin(double r, double g, double b) noexcept
        {
            double k = 0;
            if (g < b) {
                std::swap(g, b);
                k = -1;
            }
            if (r < g) {
                std::swap(r, g);
                k = -2.0 / 6 - k;
            }
            double max = r;
            double min = Math::Min(g, b);
            double c = max - min;
            return std::make_tuple(
                360.0 * Math::Abs(k + (g - b) / (6 * c + 1e-20)),
                max,
                min
            );
        }
        [[nodiscard]] static constexpr RGB HueChromaFactor(double h) noexcept
        {
            double h6 = 6.0 * Math::Fraction(h / 360.0);
            double r = Math::Abs(h6 - 3) - 1;
            double g = 2 - Math::Abs(h6 - 2);
            double b = 2 - Math::Abs(h6 - 4);

            return RGB{
                Math::Saturate(r),
                Math::Saturate(g),
                Math::Saturate(b)
            };
        }
        [[nodiscard]] static constexpr double LinearToSRGB(double v)
        {
            if (v <= 0.0031308) {
                return 12.92 * v;
            } else {
                return 1.055 * Math::Pow(v, 1.0 / 2.4) - 0.055;
            }
        }
        [[nodiscard]] static constexpr double SRGBToLinear(double v)
        {
            if (v <= 0.04045) {
                return v / 12.92;
            } else {
                return Math::Pow((v + 0.055) / 1.055, 2.4);
            }
        }
        [[nodiscard]] static constexpr double Gamma(double v, double gamma)
        {
            return Math::Pow(Math::Abs(v), gamma) * Math::Sign(v);
        }

        [[nodiscard]] static constexpr double Linearize(double v, double gamma)
        {
            return Gamma(v, 1.0 / gamma);
        }

        [[nodiscard]] static constexpr inline uint8 DoubleToUInt8(double v)
        {
            if (v >= 1.0) {
                return 255;
            }
            if (v <= 0.0) {
                return 0;
            }
            return static_cast<uint8>(v * 255.0 + 0.5);
        }
        [[nodiscard]] static constexpr inline double UInt8ToDouble(uint8 v)
        {
            return v / 255.0;
        }

        [[nodiscard]] static constexpr inline uint8 HexToDecimal(char hex)
        {
            // 1,A,aの下位4bitがそれぞれ 0x01～なので0x0Fでマスクすると
            // 0～9 => 0～9, A～F => 1～6, a～f => 1～6になる
            // (hex & 0x40) >> 6 で 0～9 => 0, a～f,A～F => 1　になる
            return (hex & 0x0F) + ((hex & 0x40) >> 6) * 9;
        }
        [[nodiscard]] static constexpr inline char DecimalToHex(uint8 d)
        {
            return d >= 10 ? (d - 10) + 'A' : d + '0';
        }
    };
}
