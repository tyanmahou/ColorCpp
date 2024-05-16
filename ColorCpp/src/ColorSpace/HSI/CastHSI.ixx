export module ColorCpp:CastHSI;
import :ColorCastTrait;
import :RGB;
import :HSI;
import :Math;
import :ColorUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<HSI>
    {
        using depend_type = RGB;
    };

    // HSI <=> RGB
    template<>
    struct ColorCastTraits<HSI, RGB>
    {
        constexpr static HSI Cast(const RGB& rgb)
        {
            auto [hue, max, min] = ColorUtil::HueMaxMin(rgb);
            double i = (rgb.r + rgb.g + rgb.b) / 3.0;
            return HSI{
                .h = hue,
                .s = i == 0 ? 0 : 1 - min / i,
                .i = i,
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, HSI>
    {
        constexpr static RGB Cast(const HSI& hsi)
        {
            auto [h, s, i] = hsi;

            double min = i * (1 - s);
            auto [cfr, cfg, cfb] = ColorUtil::HueChromaFactor(h);
            double z = 1 - Math::Abs(Math::Fmod(6.0 * Math::Fraction(h / 360.0), 2.0) - 1);
            double c = (3 * i * s) / (1 + z);
            double r = c * cfr + min;
            double g = c * cfg + min;
            double b = c * cfb + min;

            return RGB{
                .r = r,
                .g = g,
                .b = b
            };
        }
    };
}
