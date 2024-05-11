export module ColorPlus2:CastXYZ;
import :ColorCastTrait;

import :LRGB;
import :XYZ;

export namespace cp2
{
	// XYZ <=> LRGB
	template<>
	struct ColorCastTraits<XYZ, LRGB>
	{
		constexpr static XYZ Cast(const LRGB& rgb)
		{
			const auto& [r, g, b] = rgb;
			return {
				.x = 0.412391 * r + 0.357584 * g + 0.180481 * b,
				.y = 0.212639 * r + 0.715169 * g + 0.072192 * b,
				.z = 0.019331 * r + 0.119195 * g + 0.950532 * b,
			};
		}
	};
	template<>
	struct ColorCastTraits<LRGB, XYZ>
	{
		constexpr static LRGB Cast(const XYZ& xyz)
		{
			return LRGB{
					.r = 3.240970 * xyz.x - 1.537383 * xyz.y - 0.498611 * xyz.z,
					.g = -0.969244 * xyz.x + 1.875968 * xyz.y + 0.041555 * xyz.z,
					.b = 0.055630 * xyz.x - 0.203977 * xyz.y + 1.056972 * xyz.z
			};
		}
	};

	// XYZ <=> OTHER
	template<class From>
	struct ColorCastTraits<XYZ, From>
	{
		constexpr static XYZ Cast(const From& from)
		{
			return ColorCast<XYZ>(ColorCast<LRGB>(from));
		}
	};
}