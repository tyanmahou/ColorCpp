export module ColorCpp:DiffOkLab;
import :ColorDiffTrait;
import :OkLab;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<OkLab>
    {
        constexpr static double Diff(const OkLab& a, const OkLab& b)
        {
            return InternalUtil::DiffLab(a, b);
        }
    };
}
