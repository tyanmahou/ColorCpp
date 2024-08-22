export module ColorCpp:DiffXyY;
import :ColorDiffTrait;
import :XyY;
import :Math;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<XyY_<Illuminant>>
    {
        constexpr static double Diff(const XyY_<Illuminant>& a, const XyY_<Illuminant>& b)
        {
            const XyY_<Illuminant> diff = a - b;
            return Math::Sqrt(
                diff.x * diff.x +
                diff.y1 * diff.y1 +
                diff.y2 * diff.y2
            );
        }
    };
}
