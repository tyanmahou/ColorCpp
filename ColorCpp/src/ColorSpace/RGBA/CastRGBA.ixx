export module ColorCpp:CastRGBA;
import :ColorCastTrait;
import :Type;
import :RGBA;
import :RGBA32;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<RGBA>
    {
        using depend_type = RGBA32;
    };

    // RGBA <=> RGBA32
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
}
