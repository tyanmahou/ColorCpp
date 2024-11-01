export module ColorCpp:DiffHSV;
import :ColorDiffTrait;
import :HSV;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<class Model>
    struct ColorDiffTrait<HSV_<Model>>
    {
        [[nodiscard]] constexpr static double Diff(const HSV_<Model>& a, const HSV_<Model>& b)
        {
            const double h = InternalUtil::DiffHueSaturation(a, b);
            const double s = a.s - b.s;
            const double v = a.v - b.v;
            return Math::Sqrt(
                h * h
                + s * s
                + v * v
            );
        }
    };
}
