export module ColorCpp:DiffCMY;
import :ColorDiffTrait;
import :CMY;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<CMY>
    {
        [[nodiscard]] constexpr static double Diff(const CMY& a, const CMY& b)
        {
            const CMY diff = a - b;
            return Math::Sqrt(
                diff.c * diff.c +
                diff.m * diff.m +
                diff.y * diff.y
            );
        }
    };
}
