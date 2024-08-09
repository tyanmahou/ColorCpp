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
        static constexpr double Diff(const T& a, const Type& b)
        {
            return ColorDiffTrait<Type>::Diff(ColorCast<Type>(a), b);
        }
        template<class U>
        static constexpr double Diff(const Type& a, const U& b)
        {
            return ColorDiffTrait<Type>::Diff(a, ColorCast<Type>(b));
        }
        template<class T, class U>
        static constexpr double Diff(const T& a, const U& b)
        {
            return ColorDiffTrait<Type>::Diff(ColorCast<Type>(a), ColorCast<Type>(b));
        }
        static constexpr double Diff(const Type& a, const Type& b)
        {
            return ColorDiffTrait<Type>::Diff(a, b);
        }
    };
}
