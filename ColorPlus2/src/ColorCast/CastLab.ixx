export module ColorPlus2:CastLab;
import :ColorCastTrait;

import :XYZ;
import :Lab;
import :Math;

export namespace cp2
{
	// To XYZ
	template<>
	struct ColorCastTraits<Lab, XYZ>
	{
		constexpr static Lab Cast(const XYZ& xyz)
		{
			auto&& [x, y, z] = xyz;

			constexpr double epsilon = 0.008856;
			constexpr double kappa = 903.3;

			constexpr double xr = 0.950456;
			constexpr double yr = 1.0;
			constexpr double zr = 1.088754;

			double fx = (x > epsilon) ? Cbrt(x / xr) : (kappa * x + 16.0) / 116.0;
			double fy = (y > epsilon) ? Cbrt(y / yr) : (kappa * y + 16.0) / 116.0;
			double fz = (z > epsilon) ? Cbrt(x / xr) : (kappa * z + 16.0) / 116.0;

			return Lab{
				.l = 116.0 * fy - 16.0,
				.a = 500.0 * (fx - fy),
				.b = 200.0 * (fy - fz)
			};
		}
	};
	template<class From>
	struct ColorCastTraits<Lab, From>
	{
		constexpr static Lab Cast(const From& from)
		{
			return ColorCast<Lab>(ColorCast<XYZ>(from));
		}
	};

	// To XYZ
	template<>
	struct ColorCastTraits<XYZ, Lab>
	{
		constexpr static XYZ Cast(const Lab& lab)
		{
			constexpr double epsilon = 0.008856;
			constexpr double kappa = 903.3;

			constexpr double epsilon = 0.008856;
			constexpr double kappa = 903.3;
			constexpr double xr = 0.950456;
			constexpr double yr = 1.0;
			constexpr double zr = 1.088754;

			auto&& [l, a, b] = lab;

			double fy = (l + 16.0) / 116.0;
			double fx = (a  / 500.0) + fy;
			double fz = fy - (b / 200.0);

			double fx3 = Pow(fx, 3.0);
			double fy3 = Pow(fy, 3.0);
			double fz3 = Pow(fz, 3.0);

			return XYZ{
				.x = ((fx3 > epsilon) ? fx3 : (116.0 * fx - 16.0) / kappa) * xr,
				.y = ((fy3 > epsilon) ? fy3 : (116.0 * fy - 16.0) / kappa) * yr,
				.z = ((fz3 > epsilon) ? fz3 : (116.0 * fz - 16.0) / kappa) * zr
			};
		}
	};
}