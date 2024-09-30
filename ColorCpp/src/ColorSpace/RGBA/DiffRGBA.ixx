export module ColorCpp:DiffRGBA;
import :ColorDiffTrait;
import :RGBA;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGBA>
    {
        constexpr static double Diff(const RGBA& a, const RGBA& b)
        {
            const RGBA diff = a - b;
            return Math::Sqrt(
                diff.r * diff.r +
                diff.g * diff.g +
                diff.b * diff.b +
                diff.a * diff.a
            );
        }
    };
}
