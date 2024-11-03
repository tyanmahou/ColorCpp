export module ColorCpp:ColorDiff.CIE2000;
import :Lab;
import :ColorCast;
import :Math;

export namespace colorcpp
{
    struct CIE2000Diff
    {
        double kL = 1;
        double kC = 1;
        double kH = 1;
    public:
        template<class T, class U>
        [[nodiscard]] constexpr double operator()(const T& a, const U& b) const
        {
            const Lab65 labA = ColorCast<Lab65>(a);
            const Lab65 labB = ColorCast<Lab65>(b);

            // TODO
            return 0;
        }
    };
}
