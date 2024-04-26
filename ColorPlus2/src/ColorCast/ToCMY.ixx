export module ColorPlus2:ToCMY;
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
}