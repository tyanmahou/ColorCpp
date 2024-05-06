export module ColorPlus2:CastRGBA;
import :ColorCastTrait;
import :RGBA;
import :RGB;
import :Math;

export namespace cp2
{
    // RGBA <=> RGB
    template<>
    struct ColorCastTraits<RGBA, RGB>
    {
        constexpr static RGBA Cast(const RGB& rgb)
        {
            return
            {
                .r = rgb.r,
                .g = rgb.g,
                .b = rgb.b,
                .a = 1.0
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, RGBA>
    {
        constexpr static RGB Cast(const RGBA& rgba)
        {
            return
            {
                .r = rgba.r,
                .g = rgba.g,
                .b = rgba.b
            };
        }
    };

    // RGBA <=> OTHER
    template<class From>
    struct ColorCastTraits<RGBA, From>
    {
        constexpr static RGBA Cast(const From& from)
        {
            return ColorCast<RGBA>(ColorCast<RGB>(from));
        }
    };
}