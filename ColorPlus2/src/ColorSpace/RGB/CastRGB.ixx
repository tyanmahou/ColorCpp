export module ColorPlus2:CastRGB;
import :ColorCastTrait;

import :RGB;
import :RGBA;
import :RGB24;
import :RGBA32;
import :Type;

export namespace colorp2
{
    template<>
    struct ColorCastDependency<RGB>
    {
        using depend_type = RGBA;
    };
    // RGB <=> RGBA
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

    // RGB <=> RGBA32
    template<>
    struct ColorCastTraits<RGB, RGBA32>
    {
        constexpr static RGB Cast(const RGBA32& rgba)
        {
            return
            {
                .r = UInt8ToDouble(rgba.r),
                .g = UInt8ToDouble(rgba.g),
                .b = UInt8ToDouble(rgba.b)
            };
        }
    };

    template<>
    struct ColorCastTraits<RGBA32, RGB>
    {
        constexpr static RGBA32 Cast(const RGB& rgb)
        {
            return
            {
                .r = DoubleToUInt8(rgb.r),
                .g = DoubleToUInt8(rgb.g),
                .b = DoubleToUInt8(rgb.b),
                .a = 255,
            };
        }
    };

    // RGB <=> RGB24
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
}