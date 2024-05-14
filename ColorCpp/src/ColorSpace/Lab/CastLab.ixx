export module ColorCpp:CastLab;
import :ColorCastTrait;

import :XYZ;
import :Lab;
import :Math;
import :Constants;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<Lab_<Illuminant>>
    {
        using depend_type = XYZ_<Illuminant>;
    };

    // Lab <=> XYZ
    template<class Illuminant>
    struct ColorCastTraits<Lab_<Illuminant>, XYZ_<Illuminant>>
    {
        constexpr static Lab_<Illuminant> Cast(const XYZ_<Illuminant>& xyz)
        {
            auto&& [x, y, z] = xyz;

            const auto& [xr, yr, zr] = WhitePoint<Illuminant>;

            double fx = (x > Epsilon) ? Math::Cbrt(x / xr) : (Kappa * x + 16.0) / 116.0;
            double fy = (y > Epsilon) ? Math::Cbrt(y / yr) : (Kappa * y + 16.0) / 116.0;
            double fz = (z > Epsilon) ? Math::Cbrt(z / zr) : (Kappa * z + 16.0) / 116.0;

            return {
                .l = 116.0 * fy - 16.0,
                .a = 500.0 * (fx - fy),
                .b = 200.0 * (fy - fz)
            };
        }
    };
    template<class Illuminant>
    struct ColorCastTraits<XYZ_<Illuminant>, Lab_<Illuminant>>
    {
        constexpr static XYZ_<Illuminant> Cast(const Lab_<Illuminant>& lab)
        {
            const auto& [xr, yr, zr] = WhitePoint<Illuminant>;

            auto&& [l, a, b] = lab;

            double fy = (l + 16.0) / 116.0;
            double fx = (a / 500.0) + fy;
            double fz = fy - (b / 200.0);

            double fx3 = fx * fx * fx;
            double fy3 = fy * fy * fy;
            double fz3 = fz * fz * fz;

            return {
                .x = ((fx3 > Epsilon) ? fx3 : (116.0 * fx - 16.0) / Kappa) * xr,
                .y = ((fy3 > Epsilon) ? fy3 : (116.0 * fy - 16.0) / Kappa) * yr,
                .z = ((fz3 > Epsilon) ? fz3 : (116.0 * fz - 16.0) / Kappa) * zr
            };
        }
    };
}
