export module ColorCpp:CastHSV;
import :ColorCastTrait;
import :RGB;
import :HSV;
import :Math;
import :ColorUtil;

export namespace colorcpp
{
    template<class Model>
    struct ColorCastDependency<HSV_<Model>>
    {
        using depend_type = RGB;
    };

    // HSV(Cylinder) <=> RGB
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

            auto [cfr, cfg, cfb] = ColorUtil::HueChromaFactor(h);

            double r = ((cfr - 1) * s + 1) * v;
            double g = ((cfg - 1) * s + 1) * v;
            double b = ((cfb - 1) * s + 1) * v;

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };

    // HSV(Cone) <=> RGB
    template<>
    struct ColorCastTraits<HSVCone, RGB>
    {
        constexpr static HSVCone Cast(const RGB& rgb)
        {
            // Fast HSV to RGB
            auto [hue, max, min] = ColorUtil::HueMaxMin(rgb);
            return HSVCone{
                .h = hue,
                .s = max - min,
                .v = max
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HSVCone>
    {
        constexpr static RGB Cast(const HSVCone& hsv)
        {
            auto [h, s, v] = hsv;

            auto [cfr, cfg, cfb] = ColorUtil::HueChromaFactor(h);

            double c = s;

            double r = (v - c) + c * cfr;
            double g = (v - c) + c * cfg;
            double b = (v - c) + c * cfb;

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };
}
