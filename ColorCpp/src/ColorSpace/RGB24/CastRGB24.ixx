export module ColorCpp:CastRGB24;
import :ColorCastTrait;

import :RGBA32;
import :RGB24;
import :RGBA;
import :RGB;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<RGB24>
    {
        using depend_type = RGBA32;
    };

    // RGB24 <=> RGBA32
    template<>
    struct ColorCastTraits<RGB24, RGBA32>
    {
        [[nodiscard]] constexpr static RGB24 Cast(const RGBA32& rgba)
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
        [[nodiscard]] constexpr static RGBA32 Cast(const RGB24& rgb)
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
        [[nodiscard]] constexpr static RGB24 Cast(const RGBA& rgba)
        {
            return
            {
                .r = InternalUtil::DoubleToUInt8(rgba.r),
                .g = InternalUtil::DoubleToUInt8(rgba.g),
                .b = InternalUtil::DoubleToUInt8(rgba.b)
            };
        }
    };
    template<>
    struct ColorCastTraits<RGBA, RGB24>
    {
        [[nodiscard]] constexpr static RGBA Cast(const RGB24& rgb)
        {
            return
            {
                .r = InternalUtil::UInt8ToDouble(rgb.r),
                .g = InternalUtil::UInt8ToDouble(rgb.g),
                .b = InternalUtil::UInt8ToDouble(rgb.b),
                .a = 1.0
            };
        }
    };
}
