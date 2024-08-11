export module ColorCpp:InternalUtil;
import :Math;

namespace colorcpp
{
    class InternalUtil
    {
    public:
        template<class RGBType>
        constexpr static double Diff(const RGBType& a, const RGBType& b)
        {
            const RGBType diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }
    };
}
