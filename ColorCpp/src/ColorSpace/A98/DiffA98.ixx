export module ColorCpp:DiffA98;
import :ColorDiffTrait;
import :A98;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<A98>
    {
        [[nodiscard]] constexpr static double Diff(const A98& a, const A98& b)
        {
            return InternalUtil::DiffRGB(a, b);
        }
    };
}
