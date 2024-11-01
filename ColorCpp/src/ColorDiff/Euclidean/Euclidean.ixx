export module ColorCpp:ColorDiff.Euclidean;
import :ColorCast;
import :ColorDiffTrait;

export namespace colorcpp
{
    template<class Type>
    struct EuclideanDiff
    {
    public:
        template<class T>
        [[nodiscard]] constexpr double operator()(const T& a, const Type& b) const
        {
            return ColorDiffTrait<Type>::Diff(ColorCast<Type>(a), b);
        }
        template<class U>
        [[nodiscard]] constexpr double operator()(const Type& a, const U& b) const
        {
            return ColorDiffTrait<Type>::Diff(a, ColorCast<Type>(b));
        }
        template<class T, class U>
        [[nodiscard]] constexpr double operator()(const T& a, const U& b) const
        {
            return ColorDiffTrait<Type>::Diff(ColorCast<Type>(a), ColorCast<Type>(b));
        }
        [[nodiscard]] constexpr double operator()(const Type& a, const Type& b) const
        {
            return ColorDiffTrait<Type>::Diff(a, b);
        }
    };
}
