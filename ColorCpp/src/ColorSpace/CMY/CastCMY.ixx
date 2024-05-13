export module ColorCpp:CastCMY;
import :ColorCastTrait;

import :RGB;
import :CMY;
import :CMYK;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<CMY>
    {
        using depend_type = RGB;
    };

    // CMY <=> RGB
    template<>
    struct ColorCastTraits<CMY, RGB>
    {
        constexpr static CMY Cast(const RGB& rgb)
        {
            return {
                .c = 1 - rgb.r,
                .m = 1 - rgb.g,
                .y = 1 - rgb.b,
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, CMY>
    {
        constexpr static RGB Cast(const CMY& cmy)
        {
            return {
                .r = 1 - cmy.c,
                .g = 1 - cmy.m,
                .b = 1 - cmy.y,
            };
        }
    };
}
