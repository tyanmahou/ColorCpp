export module ColorCpp:CastOkLab;
import :ColorCastTrait;

import :LRGB;
import :CastXYZ;

import :XYZ;
import :OkLab;
import :Math;

export namespace colorcpp
{
	template<>
	struct ColorCastDependency<OkLab>
	{
		using depend_type = LRGB;
	};

	// OkLab <=> XYZ65
	template<>
	struct ColorCastTraits<OkLab, XYZ65>
	{
		constexpr static OkLab Cast(const XYZ65& xyz)
		{
			auto&& [x, y, z] = xyz;

			double l = 0.8189330101 * x + 0.3618667424 * y - 0.1288597137 * z;
			double m = 0.0329845436 * x + 0.9293118715 * y + 0.0361456387 * z;
			double s = 0.0482003018 * x + 0.2643662691 * y + 0.6338517070 * z;

			double l_ = Math::Cbrt(l);
			double m_ = Math::Cbrt(m);
			double s_ = Math::Cbrt(s);

			return OkLab{
				.l = 0.2104542553 * l_ + 0.7936177850 * m_ - 0.0040720468 * s_,
				.a = 1.9779984951 * l_ - 2.4285922050 * m_ + 0.4505937099 * s_,
				.b = 0.0259040371 * l_ + 0.7827717662 * m_ - 0.8086757660 * s_,
			};
		}
	};
	template<>
	struct ColorCastTraits<XYZ65, OkLab>
	{
		constexpr static XYZ65 Cast(const OkLab& lab)
		{
			double l_ = lab.l + 0.3963377774 * lab.a + 0.2158037573 * lab.b;
			double m_ = lab.l - 0.1055613458 * lab.a - 0.0638541728 * lab.b;
			double s_ = lab.l - 0.0894841775 * lab.a - 1.2914855480 * lab.b;

			double l = l_ * l_ * l_;
			double m = m_ * m_ * m_;
			double s = s_ * s_ * s_;

			return XYZ65{
				+1.227013851 * l - 0.5577999807 * m + 0.281256149 * s,
				-0.04058017842 * l + 1.11225687 * m - 0.07167667867 * s,
				-0.07638128451 * l - 0.4214819784 * m + 1.58616322 * s,
			};
		}
	};

	// OkLab <=> RGB
	// https://bottosson.github.io/posts/oklab/#converting-from-linear-srgb-to-oklab
	template<>
	struct ColorCastTraits<OkLab, LRGB>
	{
		constexpr static OkLab Cast(const LRGB& rgb)
		{
			const auto& [r, g, b] = rgb;

			double l = 0.4122214708 * r + 0.5363325363 * g + 0.0514459929 * b;
			double m = 0.2119034982 * r + 0.6806995451 * g + 0.1073969566 * b;
			double s = 0.0883024619 * r + 0.2817188376 * g + 0.6299787005 * b;

			double l_ = Math::Cbrt(l);
			double m_ = Math::Cbrt(m);
			double s_ = Math::Cbrt(s);

			return OkLab{
				.l = 0.2104542553 * l_ + 0.7936177850 * m_ - 0.0040720468 * s_,
				.a = 1.9779984951 * l_ - 2.4285922050 * m_ + 0.4505937099 * s_,
				.b = 0.0259040371 * l_ + 0.7827717662 * m_ - 0.8086757660 * s_,
			};
		}
	};
	template<>
	struct ColorCastTraits<LRGB, OkLab>
	{
		constexpr static LRGB Cast(const OkLab& lab)
		{
			double l_ = lab.l + 0.3963377774 * lab.a + 0.2158037573 * lab.b;
			double m_ = lab.l - 0.1055613458 * lab.a - 0.0638541728 * lab.b;
			double s_ = lab.l - 0.0894841775 * lab.a - 1.2914855480 * lab.b;

			double l = l_ * l_ * l_;
			double m = m_ * m_ * m_;
			double s = s_ * s_ * s_;
			
			return LRGB{
				+4.0767416621 * l - 3.3077115913 * m + 0.2309699292 * s,
				-1.2684380046 * l + 2.6097574011 * m - 0.3413193965 * s,
				-0.0041960863 * l - 0.7034186147 * m + 1.7076147010 * s,
			};
		}
	};
}