export module ColorCpp:DiffITP;
import :ColorDiffTrait;
import :ITP;
import :Math;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<ITP>
    {
        constexpr static double Diff(const ITP& a, const ITP& b)
        {
            const ITP diff = a - b;
            return Math::Sqrt(
                diff.i * diff.i +
                diff.t * diff.t +
                diff.p * diff.p
            );
        }
    };
}
