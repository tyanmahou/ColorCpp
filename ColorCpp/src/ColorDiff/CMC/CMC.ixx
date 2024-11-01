export module ColorCpp:ColorDiff.CMC;
import :Lab;
import :ColorCast;
import :Math;
import :ColorUtil;
import <numbers>;

export namespace colorcpp
{
    struct CMCDiff
    {
        double l = 2;
        double c = 1;
    public:
        template<class T, class U>
        constexpr double operator()(const T& a, const U& b) const
        {
            const auto[l1, a1, b1] = ColorCast<Lab65>(a);
            const auto[l2, a2, b2] = ColorCast<Lab65>(b);

            const double c1 = Math::Sqrt(a1 * a1 + b1 * b1);
            const double c2 = Math::Sqrt(a2 * a2 + b2 * b2);

            double h1 = Math::Atan2(b1, b1) * 180.0 / std::numbers::pi;
            h1 = ColorUtil::RepeatHue360(h1);

            const double dL2 = Math::Pow2(l1 - l2);
            const double dC2 = Math::Pow2(c1 - c2);
            const double dH2 = Math::Pow2(a1 - a2) + Math::Pow2(b1 - b2) - dC2;

            double f = Math::Sqrt(Math::Pow4(c1) / (Math::Pow4(c1) + 1900));
            double t = (164 <= h1 && h1 <= 345)
                ? (0.56 + Math::Abs(0.2 * Math::CosDeg(h1 + 168)))
                : (0.36 + Math::Abs(0.4 * Math::CosDeg(h1 + 35)))
                ;

            double sl = (l1 < 16) ? 0.511 : (0.040975 * l1) / (1 + 0.01765 * l1);
            double sc =( 0.0638 * c1) / (1 + 0.0131 * c1) + 0.638;
            double sh = sc * (f * t + 1 - f);

            return Math::Sqrt(
                dL2 / Math::Pow2(l * sl)
                + dC2 / Math::Pow2(c * sc)
                + dH2 / Math::Pow2(sh)
            );
        }
    };
}
