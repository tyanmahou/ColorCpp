export module ColorCpp:DiffHunterLab;
import :ColorDiffTrait;
import :HunterLab;
import :InternalUtil;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<HunterLab_<Illuminant>>
    {
        [[nodiscard]] constexpr static double Diff(const HunterLab_<Illuminant>& a, const HunterLab_<Illuminant>& b)
        {
            return InternalUtil::DiffLab(a, b);
        }
    };
}
