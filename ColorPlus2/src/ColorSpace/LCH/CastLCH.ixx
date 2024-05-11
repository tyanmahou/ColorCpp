export module ColorPlus2:CastLCH;
import :ColorCastTrait;

import :Lab;
import :LCH;
import :Math;
import <numbers>;

import :RGB;
import :LRGB;
import :XYZ;
import :CastLRGB;
import :CastXYZ;
import :CastLab;

export namespace cp2
{
	// LCH <=> Lab
	template<>
	struct ColorCastTraits<LCH, Lab>
	{
		constexpr static LCH Cast(const Lab& lab)
		{
			double l = lab.l;
			double c = Math::Sqrt(lab.a * lab.a + lab.b * lab.b);
			double h = Math::Atan2(lab.b, lab.a) * 180.0 / std::numbers::pi;
			h = Math::RepeatHue360(h);
			return LCH{
				.l = l,
				.c = c,
				.h = h,
			};
		}
	};
	template<>
	struct ColorCastTraits<Lab, LCH>
	{
		constexpr static Lab Cast(const LCH& lch)
		{
			double h = lch.h * std::numbers::pi / 180.0;
			return Lab{
				.l = lch.l,
				.a = Math::Cos(h) * lch.c,
				.b = Math::Sin(h) * lch.c,
			};
		}
	};
	// LCH <=> OTHER
	template<class From>
	struct ColorCastTraits<LCH, From>
	{
		constexpr static LCH Cast(const From& from)
		{
			return ColorCast<LCH>(ColorCast<Lab>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, LCH>
	//{
	//	constexpr static To Cast(const LCH& lch)
	//	{
	//		return ColorCast<To>(ColorCast<Lab>(lch));
	//	}
	//};

	template<>
	struct ColorCastTraits<RGB, LCH>
	{
		constexpr static RGB Cast(const LCH& lch)
		{
			return ColorCast<RGB>(ColorCast<LRGB>(ColorCast<XYZ65>(ColorCast<Lab>(lch))));
		}
	};
}