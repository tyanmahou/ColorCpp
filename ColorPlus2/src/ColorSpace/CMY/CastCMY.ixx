export module ColorPlus2:CastCMY;
import :ColorCastTrait;

import :RGB;
import :CMY;
import :CMYK;
import :Math;

export namespace cp2
{
	// CMY <=> RGB
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

	// CMY <=> OTHER
	template<class From>
	struct ColorCastTraits<CMY, From>
	{
		constexpr static CMY Cast(const From& from)
		{
			return ColorCast<CMY>(ColorCast<RGB>(from));
		}
	};
	//template<class To>
	//struct ColorCastTraits<To, CMY>
	//{
	//	constexpr static To Cast(const CMY& cmy)
	//	{
	//		return ColorCast<To>(ColorCast<RGB>(cmy));
	//	}
	//};
}