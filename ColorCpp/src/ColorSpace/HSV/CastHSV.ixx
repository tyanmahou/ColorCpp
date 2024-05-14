export module ColorCpp:CastHSV;
import :ColorCastTrait;
import :RGB;
import :HSV;
import :Math;
import :ColorUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<HSV>
    {
        using depend_type = RGB;
    };

    // HSV <=> RGB
    template<>
    struct ColorCastTraits<HSV, RGB>
    {
        constexpr static HSV Cast(const RGB& rgb)
        {
            // Fast HSV to RGB
            auto [hue, max, min] = ColorUtil::HueMaxMin(rgb);
            double c = max - min;
            return HSV{
                .h = hue,
                .s = c / (max + 1e-20),
                .v = max
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HSV>
    {
        constexpr static RGB Cast(const HSV& hsv)
        {
            auto [h, s, v] = hsv;
            h /= 360.0;
            h = Math::Fraction(h);

            double r = Math::Abs(h * 6 - 3) - 1;
            double g = 2 - Math::Abs(h * 6 - 2);
            double b = 2 - Math::Abs(h * 6 - 4);

            r = ((Math::Saturate(r) - 1) * s + 1) * v;
            g = ((Math::Saturate(g) - 1) * s + 1) * v;
            b = ((Math::Saturate(b) - 1) * s + 1) * v;

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };
}
