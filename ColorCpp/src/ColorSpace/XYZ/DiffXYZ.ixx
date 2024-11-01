export module ColorCpp:DiffXYZ;
import :ColorDiffTrait;
import :XYZ;
import :Math;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<XYZ_<Illuminant>>
    {
        [[nodiscard]] constexpr static double Diff(const XYZ_<Illuminant>& a, const XYZ_<Illuminant>& b)
        {
            const XYZ_<Illuminant> diff = a - b;
            return Math::Sqrt(
                diff.x * diff.x +
                diff.y * diff.y +
                diff.z * diff.z
            );
        }
    };
}
