export module ColorCpp:DiffHSI;
import :ColorDiffTrait;
import :HSI;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<HSI>
    {
        constexpr static double Diff(const HSI& a, const HSI& b)
        {
            const double h = InternalUtil::DiffHueSaturation(a, b);
            const double s = a.s - b.s;
            const double i = a.i - b.i;
            return Math::Sqrt(
                h * h
                + s * s
                + i * i
            );
        }
    };
}
