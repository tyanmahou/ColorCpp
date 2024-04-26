# include <Siv3D.hpp>
import ColorPlus2;

namespace cp2
{
	template<class From>
	struct ColorCastTraits<s3d::ColorF, From>
	{
		constexpr static s3d::ColorF Cast(const From& from)
		{
			auto [r, g, b, a] = ColorCast<RGBA>(from);
			return { r, g, b, a };
		}
	};
	template<class From>
	struct ColorCastTraits<s3d::Color, From>
	{
		constexpr static s3d::Color Cast(const From& from)
		{
			auto [r, g, b, a] = ColorCast<RGBA32>(from);
			return { r, g, b, a };
		}
	};
}
void Main()
{
	using namespace cp2;
	constexpr RYB ryb{ 1.0, 1.0, 0.0 };
	constexpr ColorF color = ColorCast<ColorF>(ryb);

	constexpr CMY cmy{ 0.0, 0.0, 1.0 };
	constexpr ColorF color2 = ColorCast<ColorF>(cmy);

	while (System::Update())
	{
		Rect{ 0, 0, 100, 100 }.draw(color);
		Rect{ 100, 0, 100, 100 }.draw(color2);
	}
}
