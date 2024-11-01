export module ColorCpp:DiffYIQ;
import :ColorDiffTrait;
import :YIQ;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<YIQ>
    {
        [[nodiscard]] constexpr static double Diff(const YIQ& a, const YIQ& b)
        {
            const YIQ diff = a - b;
            return Math::Sqrt(
                diff.y * diff.y +
                diff.i * diff.i +
                diff.q * diff.q
            );
        }
    };
}
