export module ColorCpp:DiffRYB;
import :ColorDiffTrait;
import :RYB;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RYB>
    {
        [[nodiscard]] constexpr static double Diff(const RYB& a, const RYB& b)
        {
            const RYB diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.y * diff.y +
                diff.b * diff.b
            );
        }
    };
}
