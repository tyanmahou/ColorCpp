﻿export module ColorCpp:CastOkLCH;
import :ColorCastTrait;

import :OkLab;
import :OkLCH;
import :Math;
import :InternalUtil;
import <numbers>;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<OkLCH>
    {
        using depend_type = OkLab;
    };

    // OkLCH <=> OkLab
    template<>
    struct ColorCastTraits<OkLCH, OkLab>
    {
        [[nodiscard]] constexpr static OkLCH Cast(const OkLab& lab)
        {
            double l = lab.l;
            double c = Math::Sqrt(lab.a * lab.a + lab.b * lab.b);
            double h = Math::Atan2Deg(lab.b, lab.a);
            h = InternalUtil::RepeatHue360(h);
            return OkLCH{
                .l = l,
                .c = c,
                .h = h,
            };
        }
    };
    template<>
    struct ColorCastTraits<OkLab, OkLCH>
    {
        [[nodiscard]] constexpr static OkLab Cast(const OkLCH& lch)
        {
            double h = Math::DegToRad(lch.h);
            return OkLab{
                .l = lch.l,
                .a = Math::Cos(h) * lch.c,
                .b = Math::Sin(h) * lch.c,
            };
        }
    };
}
