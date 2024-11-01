export module ColorCpp:CastHWB;
import :ColorCastTrait;
import :RGB;
import :HWB;
import :HSV;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<HWB>
    {
        using depend_type = RGB;
    };

    // HWB <=> RGB
    template<>
    struct ColorCastTraits<HWB, RGB>
    {
        constexpr static HWB Cast(const RGB& rgb)
        {
            auto [hue, max, min] = InternalUtil::HueMaxMin(rgb);
            double c = max - min;
            return HWB{
                .h = hue,
                .w = min,
                .b = 1.0 - max
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HWB>
    {
        constexpr static RGB Cast(const HWB& hwb)
        {
            auto [h, w, b_] = hwb;
            if (w + b_ > 1) {
                double s = w + b_;
                w /= s;
                b_ /= s;
            }
            h /= 360.0;
            h = Math::Fraction(h);

            auto [cfr, cfg, cfb] = InternalUtil::HueChromaFactor(h);

            double v = 1 - b_;
            double s = v == 0 ? 1 : 1 - w / v;

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

    // HWB <=> HSV
    template<>
    struct ColorCastTraits<HWB, HSV>
    {
        constexpr static HWB Cast(const HSV& hsv)
        {
            auto&& [h, s, v] = hsv;
            const double b = 1 - v;
            const double w = (1 - s) * (1 - b);
            return HWB{ h, w, b };
        }
    };
    template<>
    struct ColorCastTraits<HSV, HWB>
    {
        constexpr static HSV Cast(const HWB& hwb)
        {
            auto [h, w, b] = hwb;
            if (w + b > 1) {
                double s = w + b;
                w /= s;
                b /= s;
            }
            double v = 1 - b;
            double s = v == 0 ? 1 : 1 - w / v;
            return HSV{ h,s,v };
        }
    };
}
