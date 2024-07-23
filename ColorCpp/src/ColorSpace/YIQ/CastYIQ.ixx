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
            return {};
        }
    };

    template<>
    struct ColorCastTraits<RGB, YIQ>
    {
        constexpr static RGB Cast(const YIQ& yiq)
        {
            auto&& [y, i, q] = yiq;
            return {};
        }
    };
}
