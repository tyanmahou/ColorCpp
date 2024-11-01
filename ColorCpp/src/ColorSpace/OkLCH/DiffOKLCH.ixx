export module ColorCpp:DiffOkLCH;
import :ColorDiffTrait;
import :OkLCH;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<OkLCH>
    {
        [[nodiscard]] constexpr static double Diff(const OkLCH& a, const OkLCH& b)
        {
            return InternalUtil::DiffLCH(a, b);
        }
    };
}
