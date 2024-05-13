export module ColorCpp:CastLRGB;
import :ColorCastTrait;

import :RGB;
import :LRGB;
export namespace colorcpp
{
	template<>
	struct ColorCastDependency<LRGB>
	{
		using depend_type = RGB;
	};

	// LRGB <=> RGB
	template<>
	struct ColorCastTraits<LRGB, RGB>
	{
		constexpr static LRGB Cast(const RGB& rgb)
		{
			return LRGB{
				SRGBToLinear(rgb.r),
				SRGBToLinear(rgb.g),
				SRGBToLinear(rgb.b),
			};
		}
	};
	template<>
	struct ColorCastTraits<RGB, LRGB>
	{
		constexpr static RGB Cast(const LRGB& rgb)
		{
			return RGB {
				LinearToSRGB(rgb.r),
				LinearToSRGB(rgb.g),
				LinearToSRGB(rgb.b)
			};
		}
	};
}