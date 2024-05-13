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
                HWB hwb{0,0,0};
                hwb.w = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(j)));
                hwb.b = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(i)));
                Rect{ 80 * i, 80 * j, 80, 80 }.draw(ColorCast<ColorF>(hwb));
            }
        }

        //for (size_t i = 0; i < 8; ++i) {
        //    HSL hsl = ColorCast<HSL>(base);
        //    hsl.l = s3d::Math::Lerp(0.0, 1.0, s3d::Math::InvLerp(0, 7, static_cast<double>(i)));
        //    Rect{ 80 * i, 000, 80, 80 }.draw(ColorCast<ColorF>(hsl));
        //}
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
