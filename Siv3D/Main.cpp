# include <Siv3D.hpp>
# include "SivColorCpp.hpp"

import ColorCpp;

void Main()
{
    Window::Resize(640, 640);
    using namespace colorcpp;
    Color base = Palette::Red;

    while (System::Update())
    {
        for (size_t i = 0; i < 8; ++i) {
            for (size_t j = 0; j < 8; ++j) {
                HSI hsi{0,0,0};
                hsi.h = Utility::RepeatHue360(s3d::Scene::Time() * 60.0);
                hsi.s = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(j)));
                hsi.i = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(i)));
                Rect{ 80 * i, 80 * j, 80, 80 }.draw(ColorCast<ColorF>(hsi));
            }
        }

        //for (size_t i = 0; i < 8; ++i) {
        //    LCH lch = ColorCast<LCH>(base);
        //    lch.l = s3d::Math::Lerp(0.0, 100.0, s3d::Math::InvLerp(0, 7, static_cast<double>(i)));
        //    lch = colorcpp::Utility::ClampChroma(lch);
        //    Rect{ 80 * i, 80, 80, 80 }.draw(ColorCast<ColorF>(lch));
        //}
        //for (size_t i = 0; i < 8; ++i) {
        //    OkLCH lch = ColorCast<OkLCH>(base);
        //    lch.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(i)));
        //    lch = colorcpp::Utility::ClampChroma(lch);
        //    Rect{ 80 * i, 160, 80, 80 }.draw(ColorCast<ColorF>(lch));
        //}
    }
}
