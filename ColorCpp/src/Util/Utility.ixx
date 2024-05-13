export module ColorCpp:Utility;
import :Math;
import :ColorUtil;
import :RGB;
import :LCH;
import :OkLCH;

import :ColorCast;

export namespace colorcpp
{
    class Utility
    {
    public:
        static constexpr bool InRangeRGB(const RGB& rgb)
        {
            return 0 <= rgb.r && rgb.r <= 1.0 &&
                0 <= rgb.g && rgb.g <= 1.0 &&
                0 <= rgb.b && rgb.b <= 1.0;
        }
        static constexpr bool Displayable(const RGB& rgb)
        {
            return InRangeRGB(rgb);
        }
        template<class Color>
        static constexpr bool Displayable(const Color& color)
        {
            return InRangeRGB(ColorCast<RGB>(color));
        }

        static constexpr RGB ClampRGB(const RGB& rgb)
        {
            return {
                Math::Saturate(rgb.r),
                Math::Saturate(rgb.g),
                Math::Saturate(rgb.b)
            };
        }

        static constexpr LCH ClampChroma(const LCH& lch)
        {
            if (Displayable(lch)) {
                return lch;
            }
            LCH clamped = lch;
            clamped.c = 0;
            if (!Displayable(clamped)) {
                return ColorCast<LCH>(ClampRGB(ColorCast<RGB>(clamped)));
            }

            double start = 0, end = lch.c;
            constexpr double e = 0.001831054687;
            double c = clamped.c;
            while (end - start > e) {
                clamped.c = start + (end - start) * 0.5;
                if (Displayable(clamped)) {
                    c = clamped.c;
                    start = clamped.c;
                } else {
                    end = clamped.c;
                }
            }
            if (!Displayable(clamped)) {
                clamped.c = c;
            }
            return clamped;
        }
        static constexpr OkLCH ClampChroma(const OkLCH& lch)
        {
            if (Displayable(lch)) {
                return lch;
            }
            OkLCH clamped = lch;
            clamped.c = 0;
            if (!Displayable(clamped)) {
                return ColorCast<OkLCH>(ClampRGB(ColorCast<RGB>(clamped)));
            }

            double start = 0, end = lch.c;
            constexpr double e = 0.00004882812;
            double c = clamped.c;
            while (end - start > e) {
                clamped.c = start + (end - start) * 0.5;
                if (Displayable(clamped)) {
                    c = clamped.c;
                    start = clamped.c;
                } else {
                    end = clamped.c;
                }
            }
            if (!Displayable(clamped)) {
                clamped.c = c;
            }
            return clamped;
        }

        static constexpr inline double RepeatHue360(double h) noexcept
        {
            return ColorUtil::RepeatHue360(h);
        }
    };
}
