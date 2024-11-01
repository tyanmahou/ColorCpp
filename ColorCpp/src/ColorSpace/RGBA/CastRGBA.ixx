export module ColorCpp:CastRGBA;
import :ColorCastTrait;
import :InternalUtil;
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
        [[nodiscard]] constexpr static RGBA Cast(const RGBA32& rgba)
        {
            return
            {
                .r = InternalUtil::UInt8ToDouble(rgba.r),
                .g = InternalUtil::UInt8ToDouble(rgba.g),
                .b = InternalUtil::UInt8ToDouble(rgba.b),
                .a = InternalUtil::UInt8ToDouble(rgba.a),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGBA32, RGBA>
    {
        [[nodiscard]] constexpr static RGBA32 Cast(const RGBA& rgba)
        {
            return
            {
                .r = InternalUtil::DoubleToUInt8(rgba.r),
                .g = InternalUtil::DoubleToUInt8(rgba.g),
                .b = InternalUtil::DoubleToUInt8(rgba.b),
                .a = InternalUtil::DoubleToUInt8(rgba.a),
            };
        }
    };
}
