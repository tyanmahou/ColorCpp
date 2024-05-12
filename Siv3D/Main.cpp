# include <Siv3D.hpp>
# include "SivColorPlus2.hpp"

import ColorPlus2;

void Main()
{
	Scene::Resize(800, 600);
	using namespace colorp2;
	Color base = Palette::Red;

	while (System::Update())
	{
		for (size_t i = 0; i < 8; ++i) {
			HSL hsl = ColorCast<HSL>(base);
			hsl.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, i));
			Rect{ 100 * i, 000, 100, 100 }.draw(ColorCast<ColorF>(hsl));
		}
		for (size_t i = 0; i < 8; ++i) {
			LCH lch = ColorCast<LCH>(base);
			lch.l = s3d::Math::Lerp(0.0, 100.0, s3d::Math::InvLerp(0, 7, i));
			lch = colorp2::Utility::ClampChroma(lch);
			Rect{ 100 * i, 100, 100, 100 }.draw(ColorCast<ColorF>(lch));
		}
		for (size_t i = 0; i < 8; ++i) {
			OkLCH lch = ColorCast<OkLCH>(base);
			lch.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, i));
			lch = colorp2::Utility::ClampChroma(lch);
			Rect{ 100 * i, 200, 100, 100 }.draw(ColorCast<ColorF>(lch));
		}
	}
}
