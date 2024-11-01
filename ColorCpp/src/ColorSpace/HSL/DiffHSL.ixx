export module ColorCpp:DiffHSL;
import :ColorDiffTrait;
import :HSL;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<class Model>
    struct ColorDiffTrait<HSL_<Model>>
    {
        [[nodiscard]] constexpr static double Diff(const HSL_<Model>& a, const HSL_<Model>& b)
        {
            const double h = InternalUtil::DiffHueSaturation(a, b);
            const double s = a.s - b.s;
            const double l = a.l - b.l;
            return Math::Sqrt(
                h * h
                + s * s
                + l * l
            );
        }
    };
}
