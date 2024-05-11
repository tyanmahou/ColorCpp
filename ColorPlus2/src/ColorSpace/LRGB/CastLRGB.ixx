export module ColorPlus2:CastLRGB;
import :ColorCastTrait;

import :RGB;
import :LRGB;
export namespace cp2
{
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

	// LRGB <=> OTHER
	template<class From>
	struct ColorCastTraits<LRGB, From>
	{
		constexpr static LRGB Cast(const From& from)
		{
			return ColorCast<LRGB>(ColorCast<RGB>(from));
		}
	};
}