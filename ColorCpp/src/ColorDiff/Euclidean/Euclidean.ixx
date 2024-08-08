export module ColorCpp:ColorDiff.Euclidean;
import :ColorCast;
import :ColorDiffTrait;

export namespace colorcpp
{
    template<class Type>
    struct EuclideanDiffrence
    {
    public:
        template<class U>
        constexpr double operator()(const U& a, const Type& b)
        {
            return ColorDiffTrait<Type>::Diffrence(ColorCast<Type>(a), b);
        }
        template<class U>
        constexpr double operator()(const Type& a, const U& b)
        {
            return ColorDiffTrait<Type>::Diffrence(a, ColorCast<Type>(b));
        }
        template<class U, class V>
        constexpr double operator()(const Type& a, const U& b)
        {
            return ColorDiffTrait<Type>::Diffrence(ColorCast<Type>(a), ColorCast<Type>(b));
        }
        constexpr double operator()(const Type& a, const Type& b)
        {
            return ColorDiffTrait<Type>::Diffrence(a, b);
        }
    };

    template<class Type>
    constexpr inline EuclideanDiffrence<Type> EuclideanDiff{};
}
