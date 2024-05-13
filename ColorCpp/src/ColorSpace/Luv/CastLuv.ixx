export module ColorCpp:CastLuv;
import :ColorCastTrait;

import :XYZ;
import :Luv;
import :Math;
import :Constants;

namespace colorcpp
{
    namespace
    {
        inline constexpr double CalcU(double x, double y, double z)
        {
            return (4 * x) / (x + 15 * y + 3 * z);
        }
        template<class Illuminant>
        inline constexpr double CalcU(const XYZ_<Illuminant>& xyz)
        {
            return CalcU(xyz.x, xyz.y, xyz.z);
        }
        inline constexpr double CalcV(double x, double y, double z)
        {
            return (9 * y) / (x + 15 * y + 3 * z);
        }
        template<class Illuminant>
        inline constexpr double CalcV(const XYZ_<Illuminant>& xyz)
        {
            return CalcV(xyz.x, xyz.y, xyz.z);
        }
    }
}
export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<Luv_<Illuminant>>
    {
        using depend_type = XYZ_<Illuminant>;
    };

    // Luv <=> XYZ65
    template<class Illuminant>
    struct ColorCastTraits<Luv_<Illuminant>, XYZ_<Illuminant>>
    {
        constexpr static Luv_<Illuminant> Cast(const XYZ_<Illuminant>& xyz)
        {
            const auto& w = WhitePoint<Illuminant>;
            auto&& [x, y, z] = xyz;

            const double ny = y / w.y;

            const double l = ny <= Epsilon ? Kappa * ny : 116.0 * Math::Cbrt(ny) - 16.0;
            const double u = 13 * l * (CalcU(xyz) - CalcU(w));
            const double v = 13 * l * (CalcV(xyz) - CalcV(w));
            return { l, u, v };
        }
    };
    template<class Illuminant>
    struct ColorCastTraits<XYZ_<Illuminant>, Luv_<Illuminant>>
    {
        constexpr static XYZ_<Illuminant> Cast(const Luv_<Illuminant>& luv)
        {
            const auto& w = WhitePoint<Illuminant>;
            auto&& [l, u, v] = luv;

            const double up = u / (13 * l) + CalcU(w);
            const double vp = v / (13 * l) + CalcV(w);

            const double cbrty = ((l + 16) / 116);
            const double ny = cbrty * cbrty * cbrty;

            const double y = w.y * (l <= 8 ? l / Kappa : ny);
            double x = (y * (9 * up)) / (4 * up);
            double z = (y * (12 - 3 * up - 20 * vp)) / (4 * vp);
            return {x, y, z};
        }
    };
}
