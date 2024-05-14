export module ColorCpp:CastHSL;
import :ColorCastTrait;
import :RGB;
import :HSL;
import :Math;
import :ColorUtil;

namespace
{
    constexpr inline double HueToRGB(double min, double max, double h)
    {
        if (h < 0) {
            h += 1;
        }
        if (h > 1) {
            h -= 1;
        }
        if (6 * h < 1) {
            return min + (max - min) * 6 * h;
        }
        if (2 * h < 1) {
            return max;
        }
        if (3 * h < 2) {
            return min + (max - min) * (2.0 / 3.0 - h) * 6;
        }
        return min;
    }
}
export namespace colorcpp
{
    template<class Model>
    struct ColorCastDependency<HSL_<Model>>
    {
        using depend_type = RGB;
    };

    // HSL(Cylinder) <=> RGB
    template<>
    struct ColorCastTraits<HSL, RGB>
    {
        constexpr static HSL Cast(const RGB& rgb)
        {
            auto [hue, max, min] = ColorUtil::HueMaxMin(rgb);
            double c = max - min;
            double s = 0;
            double l = (max + min) / 2.0;

            if (c != 0) {
                s = (l < 0.5) ? c / (max + min) : c / (2.0 - max - min);
            }
            return HSL{
                .h = hue,
                .s = s,
                .l = l
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HSL>
    {
        constexpr static RGB Cast(const HSL& hsl)
        {
            const auto& [h, s, l] = hsl;

            if (s == 0) {
                return RGB{ l, l, l };
            }

            double h1 = Math::Fraction(h / 360.0);
            double max = (l < 0.5) ? (l * (1 + s)) : (l + s - (s * l));
            double min = 2 * l - max;

            double r = HueToRGB(min, max, h1 + 1 / 3.0);
            double g = HueToRGB(min, max, h1);
            double b = HueToRGB(min, max, h1 - 1 / 3.0);

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };

    // HSL(Conde) <=> RGB
    template<>
    struct ColorCastTraits<HSLCone, RGB>
    {
        constexpr static HSLCone Cast(const RGB& rgb)
        {
            auto [hue, max, min] = ColorUtil::HueMaxMin(rgb);
            return HSLCone{
                .h = hue,
                .s = max - min,
                .l = (max + min) / 2.0
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HSLCone>
    {
        constexpr static RGB Cast(const HSLCone& hsl)
        {
            const auto& [h, s, l] = hsl;

            if (s == 0) {
                return RGB{ l, l, l };
            }

            double h1 = Math::Fraction(h / 360.0);
            double max = l + s * 0.5;
            double min = l - s * 0.5;

            double r = HueToRGB(min, max, h1 + 1 / 3.0);
            double g = HueToRGB(min, max, h1);
            double b = HueToRGB(min, max, h1 - 1 / 3.0);

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };
}
