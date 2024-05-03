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
	Color base = Color{U"#FF0000"}; //Palette::Red;
	s3d::HSV hsv = base;
	LCH lch = ColorCast<LCH>(base);
	OkLCH oklch = ColorCast<OkLCH>(base);

	while (System::Update())
	{
		ClearPrint();
		Print << U"({}, {}, {})"_fmt(lch.l, lch.c, lch.h);
		Print << U"({}, {}, {})"_fmt(oklch.l, oklch.c, oklch.h);
		for (size_t i = 0; i < 8; ++i) {
			hsv.s = i / 8.0;
			Rect{ 100 * i, 0, 100, 100 }.draw(hsv);
		}
		for (size_t i = 0; i < 8; ++i) {
			LCH copy = lch;
			copy.l = s3d::Math::Lerp(0.0, 100.0, s3d::Math::InvLerp(0, 7, i));
			Rect{ 100 * i, 100, 100, 100 }.draw(ColorCast<ColorF>(copy));
		}
		for (size_t i = 0; i < 8; ++i) {
			OkLCH copy = oklch;
			copy.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, i));
			Rect{ 100 * i, 200, 100, 100 }.draw(ColorCast<ColorF>(copy));
		}
	}
}
