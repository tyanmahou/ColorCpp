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
	template<>
	struct ColorCastTraits<RGBA, s3d::ColorF>
	{
		constexpr static RGBA Cast(const s3d::ColorF& from)
		{
			auto&& [r, g, b, a] = from;
			return { r, g, b, a };
		}
	};
	template<>
	struct ColorCastTraits<RGB, s3d::ColorF>
	{
		constexpr static RGB Cast(const s3d::ColorF& from)
		{
			return ColorCast<RGB>(ColorCast<RGBA>(from));
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
	template<>
	struct ColorCastTraits<RGBA32, s3d::Color>
	{
		constexpr static RGBA32 Cast(const s3d::Color& from)
		{
			auto&& [r, g, b, a] = from;
			return { r, g, b, a };
		}
	};
	template<>
	struct ColorCastTraits<RGB, s3d::Color>
	{
		constexpr static RGB Cast(const s3d::Color& from)
		{
			return ColorCast<RGB>(ColorCast<RGBA32>(from));
		}
	};
}
void Main()
{
	Scene::Resize(800, 600);
	using namespace cp2;
	Color base = Palette::Red;
	s3d::HSV hsv = base;
	cp2::HSV hsv2 = ColorCast<cp2::HSV>(base);

	while (System::Update())
	{
		ClearPrint();
		for (size_t i = 0; i < 8; ++i) {
			s3d::HSV copy = hsv;
			copy.h = s3d::Math::Lerp(0.0, 360.0, s3d::Math::InvLerp(0, 7, i));
			Rect{ 100 * i, 000, 100, 100 }.draw(copy);
		}
		for (size_t i = 0; i < 8; ++i) {
			cp2::HSV copy = hsv2;
			copy.h = s3d::Math::Lerp(0.0, 360.0, s3d::Math::InvLerp(0, 7, i));
			Rect{ 100 * i, 100, 100, 100 }.draw(ColorCast<ColorF>(copy));
		}
	}
}
