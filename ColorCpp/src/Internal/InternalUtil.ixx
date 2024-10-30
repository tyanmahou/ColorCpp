export module ColorCpp:InternalUtil;
import :ColorUtil;
import :Math;
import <numbers>;

namespace colorcpp
{
    class InternalUtil
    {
    public:
        template<class HS>
        constexpr static double DiffHueSaturation(const HS& a, const HS& b)
        {
            const double ah = ColorUtil::RepeatHue360(a.h);
            const double bh = ColorUtil::RepeatHue360(b.h);
            const double dH = Math::Sin((((bh - ah + 360) / 2) * std::numbers::pi) / 180);
            return 2 * Math::Sqrt(a.s * b.s) * dH;
        }
        template<class HC>
        constexpr static double DiffHueChroma(const HC& a, const HC& b)
        {
            const double ah = ColorUtil::RepeatHue360(a.h);
            const double bh = ColorUtil::RepeatHue360(b.h);
            const double dH = Math::Sin((((bh - ah + 360) / 2) * std::numbers::pi) / 180);
            return 2 * Math::Sqrt(a.c * b.c) * dH;
        }
        constexpr static double DiffHue(double a, double b)
        {
            const double ah = ColorUtil::RepeatHue360(a);
            const double bh = ColorUtil::RepeatHue360(b);
            if (Math::Abs(bh - ah) > 180) {
                return ah - (bh - 360 * Math::Sign(bh - ah));
            } else {
                return bh - ah;
            }
        }
        template<class RGBType>
        constexpr static double DiffRGB(const RGBType& a, const RGBType& b)
        {
            const RGBType diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }

        template<class LabType>
        constexpr static double DiffLab(const LabType& a, const LabType& b)
        {
            const LabType diff = a - b;
            return Math::Sqrt(
                diff.l * diff.l +
                diff.a * diff.a +
                diff.b * diff.b
            );
        }
    };
}
