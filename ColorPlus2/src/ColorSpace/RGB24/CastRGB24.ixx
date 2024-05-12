export module ColorPlus2:CastRGB24;
import :ColorCastTrait;

import :RGBA32;
import :RGB24;
import :RGBA;
import :RGB;
import :Math;

export namespace colorp2
{
    // RGB24 <=> RGBA32
    template<>
    struct ColorCastTraits<RGB24, RGBA32>
    {
        constexpr static RGB24 Cast(const RGBA32& rgba)
        {
            return
            {
                .r = rgba.r,
                .g = rgba.g,
                .b = rgba.b
            };
        }
    };
    template<>
    struct ColorCastTraits<RGBA32, RGB24>
    {
        constexpr static RGBA32 Cast(const RGB24& rgb)
        {
            return
            {
                .r = rgb.r,
                .g = rgb.g,
                .b = rgb.b,
                .a = 255
            };
        }
    };

    // RGB24 <=> RGBA
    template<>
    struct ColorCastTraits<RGB24, RGBA>
    {
        constexpr static RGB24 Cast(const RGBA& rgba)
        {
            return
            {
                .r = DoubleToUInt8(rgba.r),
                .g = DoubleToUInt8(rgba.g),
                .b = DoubleToUInt8(rgba.b)
            };
        }
    };
    template<>
    struct ColorCastTraits<RGBA, RGB24>
    {
        constexpr static RGBA Cast(const RGB24& rgb)
        {
            return
            {
                .r = UInt8ToDouble(rgb.r),
                .g = UInt8ToDouble(rgb.g),
                .b = UInt8ToDouble(rgb.b),
                .a = 1.0
            };
        }
    };

    // RGB24 <=> OTHER
    template<class From>
    struct ColorCastTraits<RGB24, From>
    {
        constexpr static RGB24 Cast(const From& from)
        {
            return ColorCast<RGB24>(ColorCast<RGBA32>(from));
        }
    };
}