export module ColorPlus2:CastHunterLab;
import :ColorCastTrait;

import :CastXYZ;

import :XYZ;
import :HunterLab;
import :Math;

export namespace cp2
{
	// HunterLab <=> XYZ
	template<>
	struct ColorCastTraits<HunterLab, XYZ>
	{
		constexpr static HunterLab Cast(const XYZ& xyz)
		{
			double x = 100.0 * xyz.x;
			double y = 100.0 * xyz.y;
			double z = 100.0 * xyz.z;


			return HunterLab{
				.l = 10.0 * Math::Sqrt(y),
				.a = (y != 0) ? (17.5 * (1.02 * x- y) / Math::Sqrt(y)) : 0,
				.b = (y != 0) ? (7.0 * (y - 0.847 * z) / Math::Sqrt(y)) : 0
			};
		}
	};
	template<>
	struct ColorCastTraits<XYZ, HunterLab>
	{
		constexpr static XYZ Cast(const HunterLab& lab)
		{
			double x = (lab.a / 17.5) * (lab.l / 10.0);
			double y = lab.l * lab.l / 100;
			double z = lab.b / 7.0 * lab.l / 10.0;

			return XYZ{
				.x = (x + y) / 100.02,
				.y = y / 100.0,
				.z = -(z - y) / 84.7
			};
		}
	};

	// HunterLab <=> OTHER
	template<class From>
	struct ColorCastTraits<HunterLab, From>
	{
		constexpr static HunterLab Cast(const From& from)
		{
			return ColorCast<HunterLab>(ColorCast<XYZ>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, HunterLab>
	//{
	//	constexpr static To Cast(const HunterLab& lab)
	//	{
	//		return ColorCast<To>(ColorCast<XYZ>(lab));
	//	}
	//};
}