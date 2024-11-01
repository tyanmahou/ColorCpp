export module ColorCpp:DiffLab;
import :ColorDiffTrait;
import :Lab;
import :InternalUtil;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<Lab_<Illuminant>>
    {
        [[nodiscard]] constexpr static double Diff(const Lab_<Illuminant>& a, const Lab_<Illuminant>& b)
        {
            return InternalUtil::DiffLab(a, b);
        }
    };
}
