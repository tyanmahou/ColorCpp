export module ColorCpp:CastLab;
import :ColorCastTrait;

import :CastXYZ;

import :XYZ;
import :Lab;
import :Math;
import :Constants;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<Lab>
    {
        using depend_type = XYZ65;
    };

    // Lab <=> XYZ
    template<class WhitePointTag>
    struct ColorCastTraits<Lab, XYZBase<WhitePointTag>>
    {
        constexpr static Lab Cast(const XYZBase<WhitePointTag>& xyz)
        {
            auto&& [x, y, z] = xyz;

            const auto& [xr, yr, zr] = WhitePoint<XYZBase<WhitePointTag>>;

            double fx = (x > Epsilon) ? Math::Cbrt(x / xr) : (Kappa * x + 16.0) / 116.0;
            double fy = (y > Epsilon) ? Math::Cbrt(y / yr) : (Kappa * y + 16.0) / 116.0;
            double fz = (z > Epsilon) ? Math::Cbrt(z / zr) : (Kappa * z + 16.0) / 116.0;

            return Lab{
                .l = 116.0 * fy - 16.0,
                .a = 500.0 * (fx - fy),
                .b = 200.0 * (fy - fz)
            };
        }
    };
    template<class WhitePointTag>
    struct ColorCastTraits<XYZBase<WhitePointTag>, Lab>
    {
        constexpr static XYZBase<WhitePointTag> Cast(const Lab& lab)
        {
            const auto& [xr, yr, zr] = WhitePoint<XYZBase<WhitePointTag>>;

            auto&& [l, a, b] = lab;

            double fy = (l + 16.0) / 116.0;
            double fx = (a / 500.0) + fy;
            double fz = fy - (b / 200.0);

            double fx3 = fx * fx * fx;
            double fy3 = fy * fy * fy;
            double fz3 = fz * fz * fz;

            return XYZBase<WhitePointTag>{
                .x = ((fx3 > Epsilon) ? fx3 : (116.0 * fx - 16.0) / Kappa) * xr,
                    .y = ((fy3 > Epsilon) ? fy3 : (116.0 * fy - 16.0) / Kappa) * yr,
                    .z = ((fz3 > Epsilon) ? fz3 : (116.0 * fz - 16.0) / Kappa) * zr
            };
        }
    };
}
