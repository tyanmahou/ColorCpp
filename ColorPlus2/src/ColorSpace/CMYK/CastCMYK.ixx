export module ColorPlus2:CastCMYK;
import :ColorCastTrait;

import :RGB;
import :CMY;
import :CMYK;
import :Math;

export namespace colorp2
{
	// CMYK <=> CMY
	template<>
	struct ColorCastTraits<CMYK, CMY>
	{
		constexpr static CMYK Cast(const CMY& cmy)
		{
			auto&& [c, m, y] = cmy;
			double k = Math::Min(c, m, y);
			double invK = k == 1 ? 1 : 1 - k;
			return {
				.c = (c - k) / invK,
				.m = (m - k) / invK,
				.y = (y - k) / invK,
				.k = k
			};
		}
	};
	template<>
	struct ColorCastTraits<CMY, CMYK>
	{
		constexpr static CMY Cast(const CMYK& cmyk)
		{
			auto&& [c, m, y, k] = cmyk;
			return {
				.c = c * (1 - k),
				.m = m * (1 - k),
				.y = y * (1 - k),
			};
		}
	};
	// CMYK <=> RGB
	template<>
	struct ColorCastTraits<CMYK, RGB>
	{
		constexpr static CMYK Cast(const RGB& rgb)
		{
			auto&& [r, g, b] = rgb;
			double k = Math::Min(1 - r, 1 - g, 1 - b);
			double invK = k == 1 ? 1 : 1 - k;
			return {
				.c = (1 - r - k) / invK,
				.m = (1 - g - k) / invK,
				.y = (1 - b - k) / invK,
				.k = k
			};
		}
	};
	template<>
	struct ColorCastTraits<RGB, CMYK>
	{
		constexpr static RGB Cast(const CMYK& cmyk)
		{
			auto&& [c, m, y, k] = cmyk;
			return {
				.r = (1 - c) * (1 - k),
				.g = (1 - m) * (1 - k),
				.b = (1 - y) * (1 - k),
			};
		}
	};

	// CMYK <=> OTHER
	template<class From>
	struct ColorCastTraits<CMYK, From>
	{
		constexpr static CMYK Cast(const From& from)
		{
			return ColorCast<CMYK>(ColorCast<RGB>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, CMYK>
	//{
	//	constexpr static To Cast(const CMYK& cmyk)
	//	{
	//		return ColorCast<To>(ColorCast<RGB>(cmyk));
	//	}
	//};
}