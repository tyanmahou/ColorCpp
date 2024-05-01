export module ColorPlus2:CastLCH;
import :ColorCastTrait;

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
			h = Math::Repeat(h, 360.0);
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
	struct ColorCastTraits<OkLCH, Lab>
	{
		constexpr static OkLCH Cast(const Lab& lab)
		{
			double l = lab.l;
			double c = Math::Sqrt(lab.a * lab.a + lab.b * lab.b);
			double h = Math::Atan2(lab.b, lab.a) * 180.0 / std::numbers::pi;
			h = Math::Repeat(h, 360.0);
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
			return ColorCast<OkLCH>(ColorCast<Lab>(from));
		}
	};

	// To Lab
	template<>
	struct ColorCastTraits<Lab, LCH>
	{
		constexpr static Lab Cast(const LCH& lch)
		{
			return Lab{
				.l = lch.l,
				.a = Math::Cos(lch.h) * lch.c,
				.b = Math::Sin(lch.h) * lch.c,
			};
		}
	};
	template<>
	struct ColorCastTraits<Lab, OkLCH>
	{
		constexpr static Lab Cast(const OkLCH& lch)
		{
			return Lab{
				.l = lch.l,
				.a = Math::Cos(lch.h) * lch.c,
				.b = Math::Sin(lch.h) * lch.c,
			};
		}
	};
}