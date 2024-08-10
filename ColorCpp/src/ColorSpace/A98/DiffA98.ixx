export module ColorCpp:DiffA98;
import :ColorDiffTrait;
import :A98;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<A98>
    {
        constexpr static double Diff(const A98& a, const A98& b)
        {
            const A98 diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }
    };
}
