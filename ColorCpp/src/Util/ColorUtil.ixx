export module ColorCpp:ColorUtil;
import :Math;
import :RGB;
import <tuple>;
import <algorithm>;

export namespace colorcpp
{
    class ColorUtil
    {
    public:
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
        [[nodiscard]] static constexpr double Linearize(double v, double gammaInv)
        {
            return Math::Pow(v, gammaInv);
        }
        [[nodiscard]] static constexpr double Gamma(double v, double gamma)
        {
            return Math::Pow(v, gamma);
        }
    };
}
