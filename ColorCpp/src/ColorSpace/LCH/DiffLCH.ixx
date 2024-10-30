export module ColorCpp:DiffLCH;
import :ColorDiffTrait;
import :LCH;
import :InternalUtil;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorDiffTrait<LCH_<Illuminant>>
    {
        constexpr static double Diff(const LCH_<Illuminant>& a, const LCH_<Illuminant>& b)
        {
            return InternalUtil::DiffLCH(a, b);
        }
    };
}
