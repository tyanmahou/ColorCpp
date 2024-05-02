export module ColorPlus2:CastRGB;
import :ColorCastTrait;
import :RGB;
import :XYZ;
import :Math;

export namespace cp2
{
    // To RGBA32
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
    template<class From>
    struct ColorCastTraits<RGBA32, From>
    {
        constexpr static RGBA32 Cast(const From& from)
        {
            return ColorCast<RGBA32>(ColorCast<RGBA>(from));
        }
    };

    // To RGB24
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

    template<class From>
    struct ColorCastTraits<RGB24, From>
    {
        constexpr static RGB24 Cast(const From& from)
        {
            return ColorCast<RGB24>(ColorCast<RGB>(from));
        }
    };

    // To RGBA
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
    template<class From>
    struct ColorCastTraits<RGBA, From>
    {
        constexpr static RGBA Cast(const From& from)
        {
            return ColorCast<RGBA>(ColorCast<RGB>(from));
        }
    };

    // To RGB
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
}