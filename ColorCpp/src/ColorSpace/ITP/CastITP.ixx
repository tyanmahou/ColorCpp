export module ColorCpp:CastITP;
import :ColorCastTrait;
import :XYZ;
import :ITP;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<ITP>
    {
        using depend_type = XYZ65;
    };

    // ITP <=> XYZ65
    template<>
    struct ColorCastTraits<ITP, XYZ65>
    {
        constexpr static ITP Cast(const XYZ65& xyz)
        {
            return {};
        }
    };
    template<>
    struct ColorCastTraits<XYZ65, ITP>
    {
        constexpr static XYZ65 Cast(const ITP& itp)
        {
            return {};
        }
    };
}
