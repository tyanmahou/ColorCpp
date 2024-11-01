export module ColorCpp:DiffLuv;
import :ColorDiffTrait;
import :Luv;
import :Math;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<Luv_<Illuminant>>
    {
        [[nodiscard]] constexpr static double Diff(const Luv_<Illuminant>& a, const Luv_<Illuminant>& b)
        {
            const Luv_<Illuminant> diff = a - b;
            return Math::Sqrt(
                diff.l * diff.l +
                diff.u * diff.u +
                diff.v * diff.v
            );
        }
    };
}
