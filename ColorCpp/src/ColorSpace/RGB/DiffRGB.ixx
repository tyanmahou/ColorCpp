export module ColorCpp:DiffRGB;
import :ColorDiffTrait;
import :RGB;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGB>
    {
        constexpr static double Diff(const RGB& a, const RGB& b)
        {
            return InternalUtil::DiffRGB(a, b);
        }
    };
}
