export module ColorCpp:CastDisplayP3;
import :ColorCastTrait;
import :XYZ;
import :DisplayP3;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<DisplayP3>
    {
        using depend_type = XYZ65;
    };
    // DisplayP3 <=> XYZ65
    template<>
    struct ColorCastTraits<XYZ65, DisplayP3>
    {
        constexpr static DisplayP3 Cast(const XYZ65& xyz)
        {
            const auto& [x, y, z] = xyz;
            return
            {
                .r =  2.4934969119414263 * x -0.9313836179191242 * y -0.402710784450717  * z,
                .g = -0.8294889695615749 * x +1.7626640603183465 * y +0.0236246858419436 * z,
                .b =  0.0358458302437845 * x -0.0761723892680418 * y +0.9568845240076871 * z
            };
        }
    };
    template<>
    struct ColorCastTraits<DisplayP3, XYZ65>
    {
        constexpr static XYZ65 Cast(const DisplayP3& p3)
        {
            const auto& [r, g, b] = p3;
            return
            {
                .x = 0.486570948648216 * r  +0.265667693169093  * g +0.1982172852343625 * b,
                .y = 0.2289745640697487 * r +0.6917385218365062 * g +0.079286914093745  * b,
                .z =                         0.0451133818589026 * g +1.043944368900976  * b
            };
        }
    };
}
