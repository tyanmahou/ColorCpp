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
        [[nodiscard]] static constexpr inline double RepeatHue360(double h) noexcept
        {
            return Math::Repeat(h, 360.0);
        }
        [[nodiscard]] static constexpr inline std::tuple<double, double, double> HueMaxMin(const RGB& rgb) noexcept
        {
            return HueMaxMin(rgb.r, rgb.g, rgb.b);
        }
        [[nodiscard]] static constexpr inline std::tuple<double, double, double> HueMaxMin(double r, double g, double b) noexcept
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
        [[nodiscard]] static constexpr inline RGB HueChromaFactor(double h) noexcept
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
    };
}
