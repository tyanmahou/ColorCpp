export module ColorCpp:DiffDisplayP3;
import :ColorDiffTrait;
import :DisplayP3;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<DisplayP3>
    {
        constexpr static double Diff(const DisplayP3& a, const DisplayP3& b)
        {
            return InternalUtil::DiffRGB(a, b);
        }
    };
}
