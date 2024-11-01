export module ColorCpp:DiffLRGB;
import :ColorDiffTrait;
import :LRGB;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<LRGB>
    {
        [[nodiscard]] constexpr static double Diff(const LRGB& a, const LRGB& b)
        {
            return InternalUtil::DiffRGB(a, b);
        }
    };
}
