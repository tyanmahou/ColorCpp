export module ColorCpp:DiffRec2020;
import :ColorDiffTrait;
import :Rec2020;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<Rec2020>
    {
        constexpr static double Diff(const Rec2020& a, const Rec2020& b)
        {
            return InternalUtil::Diff(a, b);
        }
    };
}
