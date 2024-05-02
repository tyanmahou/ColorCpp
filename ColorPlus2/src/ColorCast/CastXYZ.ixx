export module ColorPlus2:CastXYZ;
import :ColorCastTrait;

import :RGB;
import :XYZ;

export namespace cp2
{
	// To XYZ
	template<>
	struct ColorCastTraits<XYZ, RGB>
	{
		constexpr static XYZ Cast(const RGB& rgb)
		{
			auto [r, g, b] = SRGBToLinear(rgb);
			return {
				.x = 0.4124564 * r + 0.3575761 * g + 0.1804375 * b,
				.y = 0.2126729 * r + 0.7151522 * g + 0.0721750 * b,
				.z = 0.0193339 * r + 0.1191920 * g + 0.9503041 * b,
			};
		}
	};
	template<class From>
	struct ColorCastTraits<XYZ, From>
	{
		constexpr static XYZ Cast(const From& from)
		{
			return ColorCast<XYZ>(ColorCast<RGB>(from));
		}
	};

	// To RGB
	template<>
	struct ColorCastTraits<RGB, XYZ>
	{
		constexpr static RGB Cast(const XYZ& xyz)
		{
			RGB rgb{
				.r = 3.2404542 * xyz.x -1.5371385 * xyz.y -0.4985314 * xyz.z,
				.g = -0.9692660 * xyz.x + 1.8760108 * xyz.y + 0.0415560 * xyz.z,
				.b = 0.0556434 * xyz.x -0.2040259 * xyz.y + 1.0572252 * xyz.z
			};
			return LinearToSRGB(rgb);
		}
	};
}