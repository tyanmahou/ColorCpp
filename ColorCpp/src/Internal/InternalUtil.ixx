export module ColorCpp:InternalUtil;
import :Math;

namespace colorcpp
{
    class InternalUtil
    {
    public:
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
