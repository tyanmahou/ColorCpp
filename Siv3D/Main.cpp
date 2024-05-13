# include <Siv3D.hpp>
# include "SivColorCpp.hpp"

import ColorCpp;

void Main()
{
    Scene::Resize(800, 600);
    using namespace colorcpp;
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
            lch = colorcpp::Utility::ClampChroma(lch);
            Rect{ 100 * i, 100, 100, 100 }.draw(ColorCast<ColorF>(lch));
        }
        for (size_t i = 0; i < 8; ++i) {
            OkLCH lch = ColorCast<OkLCH>(base);
            lch.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, i));
            lch = colorcpp::Utility::ClampChroma(lch);
            Rect{ 100 * i, 200, 100, 100 }.draw(ColorCast<ColorF>(lch));
        }
    }
}
