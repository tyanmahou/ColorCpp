export module ColorCpp:CastLRGB;
import :ColorCastTrait;

import :RGB;
import :LRGB;
import :ColorUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<LRGB>
    {
        using depend_type = RGB;
    };

    // LRGB <=> RGB
    template<>
    struct ColorCastTraits<LRGB, RGB>
    {
        constexpr static LRGB Cast(const RGB& rgb)
        {
            return LRGB{
                ColorUtil::SRGBToLinear(rgb.r),
                ColorUtil::SRGBToLinear(rgb.g),
                ColorUtil::SRGBToLinear(rgb.b),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, LRGB>
    {
        constexpr static RGB Cast(const LRGB& rgb)
        {
            return RGB{
                ColorUtil::LinearToSRGB(rgb.r),
                ColorUtil::LinearToSRGB(rgb.g),
                ColorUtil::LinearToSRGB(rgb.b)
            };
        }
    };
}
