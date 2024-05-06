export module ColorPlus2:CastRGB24;
import :ColorCastTrait;

import :RGB24;
import :RGBA;
import :RGB;
import :Math;

export namespace cp2
{
    // RGB24 <=> RGB
    template<>
    struct ColorCastTraits<RGB24, RGB>
    {
        constexpr static RGB24 Cast(const RGB& rgb)
        {
            return
            {
                .r = DoubleToUInt8(rgb.r),
                .g = DoubleToUInt8(rgb.g),
                .b = DoubleToUInt8(rgb.b)
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, RGB24>
    {
        constexpr static RGB Cast(const RGB24& rgb)
        {
            return
            {
                .r = UInt8ToDouble(rgb.r),
                .g = UInt8ToDouble(rgb.g),
                .b = UInt8ToDouble(rgb.b)
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
            return ColorCast<RGB24>(ColorCast<RGB>(from));
        }
    };
}