export module ColorCpp:DiffProphoto;
import :ColorDiffTrait;
import :Prophoto;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<Prophoto>
    {
        constexpr static double Diff(const Prophoto& a, const Prophoto& b)
        {
            return InternalUtil::Diff(a, b);
        }
    };
}
