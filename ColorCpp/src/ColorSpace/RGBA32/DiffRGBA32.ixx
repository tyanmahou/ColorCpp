export module ColorCpp:DiffRGBA32;
import :ColorDiffTrait;
import :RGBA32;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGBA32>
    {
        constexpr static double Diff(const RGBA32& a, const RGBA32& b)
        {
            const RGBA32 diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b +
                diff.a * diff.a
            );
        }
    };
}
