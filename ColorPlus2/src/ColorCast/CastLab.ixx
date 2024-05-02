export module ColorPlus2:CastLab;
import :ColorCastTrait;

import :RGB;
import :CastXYZ;

import :XYZ;
import :Lab;
import :Math;

export namespace cp2
{
	// To Lab
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
	template<class From>
	struct ColorCastTraits<Lab, From>
	{
		constexpr static Lab Cast(const From& from)
		{
			return ColorCast<Lab>(ColorCast<XYZ>(from));
		}
	};

	// To HunterLab
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
	template<class From>
	struct ColorCastTraits<HunterLab, From>
	{
		constexpr static HunterLab Cast(const From& from)
		{
			return ColorCast<HunterLab>(ColorCast<XYZ>(from));
		}
	};

	// To OKLab
	// https://bottosson.github.io/posts/oklab/#converting-from-linear-srgb-to-oklab
	template<>
	struct ColorCastTraits<OkLab, RGB>
	{
		constexpr static OkLab Cast(const RGB& rgb)
		{
			auto [r, g, b] = SRGBToLinear(rgb);

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
	struct ColorCastTraits<OkLab, XYZ>
	{
		constexpr static OkLab Cast(const XYZ& xyz)
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
	template<class From>
	struct ColorCastTraits<OkLab, From>
	{
		constexpr static OkLab Cast(const From& from)
		{
			return ColorCast<OkLab>(ColorCast<RGB>(from));
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
			constexpr double xr = 0.950456;
			constexpr double yr = 1.0;
			constexpr double zr = 1.088754;

			auto&& [l, a, b] = lab;

			double fy = (l + 16.0) / 116.0;
			double fx = (a  / 500.0) + fy;
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

	template<>
	struct ColorCastTraits<XYZ, OkLab>
	{
		constexpr static XYZ Cast(const OkLab& lab)
		{
			double l_ = lab.l + 0.3963377774 * lab.a + 0.2158037573 * lab.b;
			double m_ = lab.l - 0.1055613458 * lab.a - 0.0638541728 * lab.b;
			double s_ = lab.l - 0.0894841775 * lab.a - 1.2914855480 * lab.b;

			double l = l_ * l_ * l_;
			double m = m_ * m_ * m_;
			double s = s_ * s_ * s_;

			return XYZ{
				+1.227013851 * l - 0.5577999807 * m + 0.281256149 * s,
				-0.04058017842 * l + 1.11225687 * m - 0.07167667867 * s,
				-0.07638128451 * l - 0.4214819784 * m + 1.58616322 * s,
			};
		}
	};
	// To RGB
	template<>
	struct ColorCastTraits<RGB, Lab>
	{
		constexpr static RGB Cast(const Lab& lab)
		{
			return ColorCast<RGB>(ColorCast<XYZ>(lab));
		}
	};
	template<>
	struct ColorCastTraits<RGB, HunterLab>
	{
		constexpr static RGB Cast(const HunterLab& lab)
		{
			return ColorCast<RGB>(ColorCast<XYZ>(lab));
		}
	};
	template<>
	struct ColorCastTraits<RGB, OkLab>
	{
		constexpr static RGB Cast(const OkLab& lab)
		{
			double l_ = lab.l + 0.3963377774 * lab.a + 0.2158037573 * lab.b;
			double m_ = lab.l - 0.1055613458 * lab.a - 0.0638541728 * lab.b;
			double s_ = lab.l - 0.0894841775 * lab.a - 1.2914855480 * lab.b;

			double l = l_ * l_ * l_;
			double m = m_ * m_ * m_;
			double s = s_ * s_ * s_;

			RGB lrgb{
				+4.0767416621 * l - 3.3077115913 * m + 0.2309699292 * s,
				-1.2684380046 * l + 2.6097574011 * m - 0.3413193965 * s,
				-0.0041960863 * l - 0.7034186147 * m + 1.7076147010 * s,
			};
			return LinearToSRGB(lrgb);
		}
	};
}