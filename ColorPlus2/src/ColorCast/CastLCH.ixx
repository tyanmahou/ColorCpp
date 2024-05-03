export module ColorPlus2:CastLCH;
import :ColorCastTrait;

import :RGB;
import :CastLab;

import :Lab;
import :LCH;
import :Math;
import <numbers>;

export namespace cp2
{
	// To LCH
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
	template<class From>
	struct ColorCastTraits<LCH, From>
	{
		constexpr static LCH Cast(const From& from)
		{
			return ColorCast<LCH>(ColorCast<Lab>(from));
		}
	};

	// To OkLCH
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
	template<class From>
	struct ColorCastTraits<OkLCH, From>
	{
		constexpr static OkLCH Cast(const From& from)
		{
			return ColorCast<OkLCH>(ColorCast<OkLab>(from));
		}
	};

	// To Lab
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
	// To RGB
	template<>
	struct ColorCastTraits<RGB, LCH>
	{
		constexpr static RGB Cast(const LCH& lch)
		{
			return ColorCast<RGB>(ColorCast<Lab>(lch));
		}
	};
	template<>
	struct ColorCastTraits<RGB, OkLCH>
	{
		constexpr static RGB Cast(const OkLCH& lch)
		{
			return ColorCast<RGB>(ColorCast<OkLab>(lch));
		}
	};
}