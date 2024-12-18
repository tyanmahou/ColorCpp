﻿export module ColorCpp:CastLCH;
import :ColorCastTrait;

import :Lab;
import :LCH;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<LCH_<Illuminant>>
    {
        using depend_type = Lab_<Illuminant>;
    };

    // LCH <=> Lab
    template<class Illuminant>
    struct ColorCastTraits<LCH_<Illuminant>, Lab_<Illuminant>>
    {
        [[nodiscard]] constexpr static LCH_<Illuminant> Cast(const Lab_<Illuminant>& lab)
        {
            double l = lab.l;
            double c = Math::Sqrt(lab.a * lab.a + lab.b * lab.b);
            double h = Math::Atan2Deg(lab.b, lab.a);
            h = InternalUtil::RepeatHue360(h);
            return {
                .l = l,
                .c = c,
                .h = h,
            };
        }
    };
    template<class Illuminant>
    struct ColorCastTraits<Lab_<Illuminant>, LCH_<Illuminant>>
    {
        [[nodiscard]] constexpr static Lab_<Illuminant> Cast(const LCH_<Illuminant>& lch)
        {
            double h = Math::DegToRad(lch.h);
            return {
                .l = lch.l,
                .a = Math::Cos(h) * lch.c,
                .b = Math::Sin(h) * lch.c,
            };
        }
    };
}
