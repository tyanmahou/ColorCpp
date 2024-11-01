export module ColorCpp:CastLRGB;
import :ColorCastTrait;

import :RGB;
import :LRGB;
import :InternalUtil;

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
                InternalUtil::SRGBToLinear(rgb.r),
                InternalUtil::SRGBToLinear(rgb.g),
                InternalUtil::SRGBToLinear(rgb.b),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, LRGB>
    {
        constexpr static RGB Cast(const LRGB& rgb)
        {
            return RGB{
                InternalUtil::LinearToSRGB(rgb.r),
                InternalUtil::LinearToSRGB(rgb.g),
                InternalUtil::LinearToSRGB(rgb.b)
            };
        }
    };
}
