export module ColorCpp:DiffRGB;
import :ColorDiffTrait;
import :RGB;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGB>
    {
        constexpr static double Diff(const RGB& a, const RGB& b)
        {
            const RGB diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b
            );
        }
    };
}
