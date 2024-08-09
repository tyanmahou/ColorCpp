export module ColorCpp:ColorDiff;
export import :ColorDiffTrait;
export import :ColorDiff.Euclidean;


export import :DiffRGB;
import :RGB;

export namespace colorcpp
{
    struct ColorDiff
    {
    public:
        template<class T, class U>
        constexpr static double Euclidean(const T& a, const U& b)
        {
            return EuclideanDiff<RGB>::Diff(a, b);
        }
        template<class DiffType, class T, class U>
        constexpr static double Euclidean(const T& a, const U& b)
        {
            return EuclideanDiff<DiffType>::Diff(a, b);
        }
    };
}
