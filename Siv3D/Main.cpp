# include <Siv3D.hpp>
import ColorPlus2;

namespace cp2
{
	template<class From>
	struct ColorCastTraits<s3d::ColorF, From>
	{
		constexpr static s3d::ColorF Cast(const From& from)
		{
			auto [r, g, b] = ColorCast<RGB>(from);
			return { r, g, b, 1.0 };
		}
	};
	template<class From>
	struct ColorCastTraits<s3d::Color, From>
	{
		constexpr static s3d::Color Cast(const From& from)
		{
			auto colorf = ColorCast<ColorF>(from);
			return Color{ colorf };
		}
	};
}
void Main()
{
	using namespace cp2;
	constexpr RYB ryb{ 1.0, 1.0, 0.0 };
	constexpr ColorF color = ColorCast<ColorF>(ryb);

	while (System::Update())
	{
		Rect{ 0, 0, 100, 100 }.draw(color);
	}
}
