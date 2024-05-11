export module ColorPlus2:CastOkLCH;
import :ColorCastTrait;

import :OkLab;
import :OkLCH;
import :Math;
import <numbers>;

import :RGB;
import :LRGB;
import :CastLRGB;
import :CastOkLab;

export namespace cp2
{
	// OkLCH <=> OkLab
	template<>
	struct ColorCastTraits<OkLCH, OkLab>
	{
		constexpr static OkLCH Cast(const OkLab& lab)
		{
			double l = lab.l;
			double c = Math::Sqrt(lab.a * lab.a + lab.b * lab.b);
			double h = Math::Atan2(lab.b, lab.a) * 180.0 / std::numbers::pi;
			h = Math::RepeatHue360(h);
			return OkLCH{
				.l = l,
				.c = c,
				.h = h,
			};
		}
	};
	template<>
	struct ColorCastTraits<OkLab, OkLCH>
	{
		constexpr static OkLab Cast(const OkLCH& lch)
		{
			double h = lch.h * std::numbers::pi / 180.0;
			return OkLab{
				.l = lch.l,
				.a = Math::Cos(h) * lch.c,
				.b = Math::Sin(h) * lch.c,
			};
		}
	};
	// OkLCH <=> OTHER
	template<class From>
	struct ColorCastTraits<OkLCH, From>
	{
		constexpr static OkLCH Cast(const From& from)
		{
			return ColorCast<OkLCH>(ColorCast<OkLab>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, OkLCH>
	//{
	//	constexpr static To Cast(const OkLCH& lch)
	//	{
	//		return ColorCast<To>(ColorCast<OkLab>(lch));
	//	}
	//};

	template<>
	struct ColorCastTraits<RGB, OkLCH>
	{
		constexpr static RGB Cast(const OkLCH& lch)
		{
			return ColorCast<RGB>(ColorCast<LRGB>(ColorCast<OkLab>(lch)));
		}
	};
}