export module ColorCpp:DiffProphoto;
import :ColorDiffTrait;
import :Prophoto;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<Prophoto>
    {
        [[nodiscard]] constexpr static double Diff(const Prophoto& a, const Prophoto& b)
        {
            return InternalUtil::DiffRGB(a, b);
        }
    };
}
