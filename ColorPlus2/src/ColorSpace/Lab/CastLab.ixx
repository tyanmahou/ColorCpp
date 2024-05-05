export module ColorPlus2:CastLab;
import :ColorCastTrait;

import :CastXYZ;

import :XYZ;
import :Lab;
import :Math;

export namespace cp2
{
	// Lab <=> XYZ
	template<>
	struct ColorCastTraits<Lab, XYZ>
	{
		constexpr static Lab Cast(const XYZ& xyz)
		{
			auto&& [x, y, z] = xyz;

			constexpr double epsilon = 0.008856451679;
			constexpr double kappa = 903.296296296;
			const auto& [xr, yr, zr] = D65;

			double fx = (x > epsilon) ? Math::Cbrt(x / xr) : (kappa * x + 16.0) / 116.0;
			double fy = (y > epsilon) ? Math::Cbrt(y / yr) : (kappa * y + 16.0) / 116.0;
			double fz = (z > epsilon) ? Math::Cbrt(z / zr) : (kappa * z + 16.0) / 116.0;

			return Lab{
				.l = 116.0 * fy - 16.0,
				.a = 500.0 * (fx - fy),
				.b = 200.0 * (fy - fz)
			};
		}
	};
	template<>
	struct ColorCastTraits<XYZ, Lab>
	{
		constexpr static XYZ Cast(const Lab& lab)
		{
			constexpr double epsilon = 0.008856451679;
			constexpr double kappa = 903.296296296;
			const auto& [xr, yr, zr] = D65;

			auto&& [l, a, b] = lab;

			double fy = (l + 16.0) / 116.0;
			double fx = (a / 500.0) + fy;
			double fz = fy - (b / 200.0);

			double fx3 = fx * fx * fx;
			double fy3 = fy * fy * fy;
			double fz3 = fz * fz * fz;

			return XYZ{
				.x = ((fx3 > epsilon) ? fx3 : (116.0 * fx - 16.0) / kappa) * xr,
				.y = ((fy3 > epsilon) ? fy3 : (116.0 * fy - 16.0) / kappa) * yr,
				.z = ((fz3 > epsilon) ? fz3 : (116.0 * fz - 16.0) / kappa) * zr
			};
		}
	};

	// Lab <=> OTHER
	template<class From>
	struct ColorCastTraits<Lab, From>
	{
		constexpr static Lab Cast(const From& from)
		{
			return ColorCast<Lab>(ColorCast<XYZ>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, Lab>
	//{
	//	constexpr static To Cast(const Lab& lab)
	//	{
	//		return ColorCast<To>(ColorCast<XYZ>(lab));
	//	}
	//};
}