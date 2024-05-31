export module ColorCpp:CastHunterLab;
import :ColorCastTrait;

import :XYZ;
import :HunterLab;
import :Math;

namespace colorcpp
{
    namespace
    {
        inline constexpr double Ka(double xn, double yn)
        {
            return 17500.0 * (xn + yn) / 198.04;
        }
        inline constexpr double Kb(double yn, double zn)
        {
            return 7000.0 * (yn + zn) / 218.11;
        }
    }
}
export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<HunterLab_<Illuminant>>
    {
        using depend_type = XYZ_<Illuminant>;
    };

    // HunterLab <=> XYZ
    template<class Illuminant>
    struct ColorCastTraits<HunterLab_<Illuminant>, XYZ_<Illuminant>>
    {
        constexpr static HunterLab_<Illuminant> Cast(const XYZ_<Illuminant>& xyz)
        {
            constexpr auto w = WhitePoint<Illuminant>;
            constexpr auto ka = Ka(w.x, w.y);
            constexpr auto kb = Kb(w.y, w.z);

            const auto [x, y,z] = xyz / w;

            const auto sqrtY = Math::Sqrt(y);

            return {
                .l = 100.0 * sqrtY,
                .a = (y != 0) ? ka * ((x - y) / sqrtY) : 0,
                .b = (y != 0) ? kb * ((y - z) / sqrtY) : 0
            };
        }
    };
    template<class Illuminant>
    struct ColorCastTraits<XYZ_<Illuminant>, HunterLab_<Illuminant>>
    {
        constexpr static XYZ_<Illuminant> Cast(const HunterLab_<Illuminant>& lab)
        {
            constexpr auto w = WhitePoint<Illuminant>;
            constexpr auto ka = Ka(w.x, w.y);
            constexpr auto kb = Kb(w.y, w.z);

            const auto& [l, a, b] = lab;

            const double sqrtY = l / 100.0;
            const double y = sqrtY * sqrtY;

            const double x = sqrtY * a / ka + y;
            const double z = y - sqrtY * b / kb;

            return XYZ_<Illuminant>{ x, y, z } * w;
        }
    };
}
