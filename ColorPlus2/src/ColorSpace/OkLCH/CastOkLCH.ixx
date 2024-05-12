export module ColorPlus2:CastOkLCH;
import :ColorCastTrait;

import :OkLab;
import :OkLCH;
import :Math;
import <numbers>;

export namespace colorp2
{
	template<>
	struct ColorCastDependency<OkLCH>
	{
		using depend_type = OkLab;
	};

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
}