export module ColorCpp:ColorDiff.CIE76;
import :Lab;
import :ColorDiff.Euclidean;

export namespace colorcpp
{
    struct CIE76Diff
    {
    public:
        template<class T, class U>
        [[nodiscard]] constexpr double operator()(const T& a, const U& b) const
        {
            return EuclideanDiff<Lab65>{}(a, b);
        }
    };
}
