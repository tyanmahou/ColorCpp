export module ColorCpp:CastYIQ;
import :ColorCastTrait;

import :RGB;
import :YIQ;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<YIQ>
    {
        using depend_type = RGB;
    };

    // YIQ <=> RGB
    template<>
    struct ColorCastTraits<YIQ, RGB>
    {
        constexpr static YIQ Cast(const RGB& rgb)
        {
            auto&& [r, g, b] = rgb;
            return {
                .y = 0.29889531 * r + 0.58662247 * g + 0.11448223 * b,
                .i = 0.59597799 * r - 0.2741761 * g - 0.32180189 * b,
                .q = 0.21147017 * r - 0.52261711 * g + 0.31114694 * b
            };
        }
    };

    template<>
    struct ColorCastTraits<RGB, YIQ>
    {
        constexpr static RGB Cast(const YIQ& yiq)
        {
            auto&& [y, i, q] = yiq;
            return {
                .r = y + 0.95608445 * i + 0.6208885 * q,
                .g = y - 0.27137664 * i - 0.6486059 * q,
                .b = y - 1.10561724 * i + 1.70250126 * q,
            };
        }
    };
}
