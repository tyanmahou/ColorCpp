export module ColorPlus2:CastLuv;
import :ColorCastTrait;

import :XYZ;
import :Luv;
import :Math;
import :Constants;

namespace cp2
{
	namespace
	{
		inline constexpr double CalcU(double x, double y, double z)
		{
			return (4 * x) / (x + 15 * y + 3 * z);
		}
		inline constexpr double CalcU(const XYZ& xyz)
		{
			return CalcU(xyz.x, xyz.y, xyz.z);
		}
		inline constexpr double CalcV(double x, double y, double z)
		{
			return (9 * y) / (x + 15 * y + 3 * z);
		}
		inline constexpr double CalcV(const XYZ& xyz)
		{
			return CalcV(xyz.x, xyz.y, xyz.z);
		}
	}
}
export namespace cp2
{
	// Luv <=> XYZ
	template<>
	struct ColorCastTraits<Luv, XYZ>
	{
		constexpr static Luv Cast(const XYZ& xyz)
		{
			auto&& [x, y, z] = xyz;

			const double ny = y / D65.y;

			const double l = ny <= Epsilon ? Kappa * ny : 116.0 * Math::Cbrt(ny) - 16.0;
			const double u = 13 * l * (CalcU(xyz) - CalcU(D65));
			const double v = 13 * l * (CalcV(xyz) - CalcV(D65));
			return Luv{l, u, v};
		}
	};
	template<>
	struct ColorCastTraits<XYZ, Luv>
	{
		constexpr static XYZ Cast(const Luv& luv)
		{
			auto&& [l, u, v] = luv;

			const double up = u / (13 * l) + CalcU(D65);
			const double vp = v / (13 * l) + CalcV(D65);

			const double cbrty = ((l + 16) / 116);
			const double ny = cbrty * cbrty * cbrty;

			const double y = D65.y * (l <= 8 ? l / Kappa : ny);
			double x = (y * (9 * up)) / (4 * up);
			double z = (y * (12 - 3 * up - 20 * vp)) / (4 * vp);
			return XYZ{x, y, z};
		}
	};

	// Luv <=> OTHER
	template<class From>
	struct ColorCastTraits<Luv, From>
	{
		constexpr static Luv Cast(const From& from)
		{
			return ColorCast<Luv>(ColorCast<XYZ>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, Luv>
	//{
	//	constexpr static To Cast(const Luv& luv)
	//	{
	//		return ColorCast<To>(ColorCast<XYZ>(luv));
	//	}
	//};
}