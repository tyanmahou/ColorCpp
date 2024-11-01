export module ColorCpp:CastRGB;
import :ColorCastTrait;

import :RGB;
import :RGBA;
import :RGB24;
import :RGBA32;
import :InternalUtil;

export namespace colorcpp
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
        [[nodiscard]] constexpr static RGB Cast(const RGBA& rgba)
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
        [[nodiscard]] constexpr static RGBA Cast(const RGB& rgb)
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
        [[nodiscard]] constexpr static RGB Cast(const RGBA32& rgba)
        {
            return
            {
                .r = InternalUtil::UInt8ToDouble(rgba.r),
                .g = InternalUtil::UInt8ToDouble(rgba.g),
                .b = InternalUtil::UInt8ToDouble(rgba.b)
            };
        }
    };

    template<>
    struct ColorCastTraits<RGBA32, RGB>
    {
        [[nodiscard]] constexpr static RGBA32 Cast(const RGB& rgb)
        {
            return
            {
                .r = InternalUtil::DoubleToUInt8(rgb.r),
                .g = InternalUtil::DoubleToUInt8(rgb.g),
                .b = InternalUtil::DoubleToUInt8(rgb.b),
                .a = 255,
            };
        }
    };

    // RGB <=> RGB24
    template<>
    struct ColorCastTraits<RGB, RGB24>
    {
        [[nodiscard]] constexpr static RGB Cast(const RGB24& rgb)
        {
            return
            {
                .r = InternalUtil::UInt8ToDouble(rgb.r),
                .g = InternalUtil::UInt8ToDouble(rgb.g),
                .b = InternalUtil::UInt8ToDouble(rgb.b)
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB24, RGB>
    {
        [[nodiscard]] constexpr static RGB24 Cast(const RGB& rgb)
        {
            return
            {
                .r = InternalUtil::DoubleToUInt8(rgb.r),
                .g = InternalUtil::DoubleToUInt8(rgb.g),
                .b = InternalUtil::DoubleToUInt8(rgb.b)
            };
        }
    };
}
