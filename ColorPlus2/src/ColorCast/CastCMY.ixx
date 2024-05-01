export module ColorPlus2:CastCMY;
import :ColorCastTrait;

import :RGB;
import :CMY;
import :Math;

export namespace cp2
{
	// To CMY
	template<>
	struct ColorCastTraits<CMY, RGB>
	{
		constexpr static CMY Cast(const RGB& rgb)
		{
			return {
				.c = 1 - rgb.r,
				.m = 1 - rgb.g,
				.y = 1 - rgb.b,
			};
		}
	};
	template<class From>
	struct ColorCastTraits<CMY, From>
	{
		constexpr static CMY Cast(const From& from)
		{
			return ColorCast<CMY>(ColorCast<RGB>(from));
		}
	};
	// To CMYK
	template<>
	struct ColorCastTraits<CMYK, RGB>
	{
		constexpr static CMYK Cast(const RGB& rgb)
		{
			auto [r, g, b] = rgb;
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
	template<class From>
	struct ColorCastTraits<CMYK, From>
	{
		constexpr static CMYK Cast(const From& from)
		{
			return ColorCast<CMYK>(ColorCast<RGB>(from));
		}
	};

	// To RGB
	template<>
	struct ColorCastTraits<RGB, CMY>
	{
		constexpr static RGB Cast(const CMY& cmy)
		{
			return {
				.r = 1 - cmy.c,
				.g = 1 - cmy.m,
				.b = 1 - cmy.y,
			};
		}
	};
	template<>
	struct ColorCastTraits<RGB, CMYK>
	{
		constexpr static RGB Cast(const CMYK& cmyk)
		{
			auto [c, m, y, k] = cmyk;
			return {
				.r = (1 - c) * (1 - k),
				.g = (1 - m) * (1 - k),
				.b = (1 - y) * (1 - k),
			};
		}
	};
}