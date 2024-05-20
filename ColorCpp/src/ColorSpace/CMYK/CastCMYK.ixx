export module ColorCpp:CastCMYK;
import :ColorCastTrait;

import :RGB;
import :CMY;
import :CMYK;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<CMYK>
    {
        using depend_type = RGB;
    };

    // CMYK <=> CMY
    template<>
    struct ColorCastTraits<CMYK, CMY>
    {
        constexpr static CMYK Cast(const CMY& cmy)
        {
            auto&& [c, m, y] = cmy;
            double k = Math::Min(c, m, y);
            double invK = k == 1 ? 1 : 1 - k;
            return {
                .c = (c - k) / invK,
                .m = (m - k) / invK,
                .y = (y - k) / invK,
                .k = k
            };
        }
    };
    template<>
    struct ColorCastTraits<CMY, CMYK>
    {
        constexpr static CMY Cast(const CMYK& cmyk)
        {
            auto&& [c, m, y, k] = cmyk;
            return {
                .c = c * (1 - k) + k,
                .m = m * (1 - k) + k,
                .y = y * (1 - k) + k,
            };
        }
    };
    // CMYK <=> RGB
    template<>
    struct ColorCastTraits<CMYK, RGB>
    {
        constexpr static CMYK Cast(const RGB& rgb)
        {
            auto&& [r, g, b] = rgb;
            double k = Math::Min(1 - r, 1 - g, 1 - b);
            double invK = k == 1 ? 1 : 1 - k;
            return {
                .c = (1 - r - k) / invK,
                .m = (1 - g - k) / invK,
                .y = (1 - b - k) / invK,
                .k = k
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, CMYK>
    {
        constexpr static RGB Cast(const CMYK& cmyk)
        {
            auto&& [c, m, y, k] = cmyk;
            return {
                .r = (1 - c) * (1 - k),
                .g = (1 - m) * (1 - k),
                .b = (1 - y) * (1 - k),
            };
        }
    };
}
