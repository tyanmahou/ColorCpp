export module ColorCpp:CastRec2020;
import :ColorCastTrait;

import :Rec2020;
import :XYZ;
import :Math;

namespace
{
}
export namespace colorcpp
{
    template<>
    struct ColorCastDependency<Rec2020>
    {
        using depend_type = XYZ;
    };

    // Rec2020 <=> XYZ
    template<>
    struct ColorCastTraits<Rec2020, XYZ>
    {
        constexpr static Rec2020 Cast(const XYZ& xyz)
        {
            return {};
        }
    };
    template<>
    struct ColorCastTraits<XYZ, Rec2020>
    {
        constexpr static XYZ Cast(const Rec2020& rgb)
        {
            return {};
        }
    };
}
