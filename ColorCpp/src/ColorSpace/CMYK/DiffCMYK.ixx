export module ColorCpp:DiffCMYK;
import :ColorDiffTrait;
import :CMYK;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<CMYK>
    {
        constexpr static double Diff(const CMYK& a, const CMYK& b)
        {
            const CMYK diff = a - b;
            return Math::Sqrt(
                diff.c * diff.c +
                diff.m * diff.m +
                diff.y * diff.y +
                diff.k * diff.k
            );
        }
    };
}
