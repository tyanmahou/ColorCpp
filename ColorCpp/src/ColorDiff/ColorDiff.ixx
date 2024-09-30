export module ColorCpp:ColorDiff;
export import :ColorDiffTrait;
export import :ColorDiff.Euclidean;

export import :DiffA98;
export import :DiffDisplayP3;
export import :DiffProphoto;
export import :DiffRec2020;

export import :DiffRGB;
export import :DiffRGB24;
export import :DiffRGBA;
export import :DiffRGBA32;
export import :DiffRYB;
export import :DiffXyY;
export import :DiffXYZ;
export import :DiffYIQ;
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
