export module ColorPlus2:CastRGBA32;
import :ColorCastTrait;
import :RGBA32;
import :RGBA;
import :RGB24;
import :RGB;
import :Math;

export namespace colorp2
{
    // RGBA32 <=> RGBA
    template<>
    struct ColorCastTraits<RGBA32, RGBA>
    {
        constexpr static RGBA32 Cast(const RGBA& rgba)
        {
            return
            {
                .r = DoubleToUInt8(rgba.r),
                .g = DoubleToUInt8(rgba.g),
                .b = DoubleToUInt8(rgba.b),
                .a = DoubleToUInt8(rgba.a),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGBA, RGBA32>
    {
        constexpr static RGBA Cast(const RGBA32& rgba)
        {
            return
            {
                .r = UInt8ToDouble(rgba.r),
                .g = UInt8ToDouble(rgba.g),
                .b = UInt8ToDouble(rgba.b),
                .a = UInt8ToDouble(rgba.a),
            };
        }
    };

    // RGBA32 <=> RGB24
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

    // RGBA32 <=> RGB
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

    // RGBA32 <=> OTHER
    template<class From>
    struct ColorCastTraits<RGBA32, From>
    {
        constexpr static RGBA32 Cast(const From& from)
        {
            return ColorCast<RGBA32>(ColorCast<RGBA>(from));
        }
    };
}