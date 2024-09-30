export module ColorCpp:DiffRGB24;
import :ColorDiffTrait;
import :RGB24;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGB24>
    {
        constexpr static double Diff(const RGB24& a, const RGB24& b)
        {
            const RGB24 diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }
    };
}
