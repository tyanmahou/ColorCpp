export module ColorCpp:ColorDiff.CIE94;
import :Lab;
import :ColorCast;
import :Math;

export namespace colorcpp
{
    struct CIE94Diff
    {
        double kL = 1;
        double k1 = 0.045;
        double k2 = 0.015;
    public:
        template<class T, class U>
        constexpr double operator()(const T& a, const U& b) const
        {
            const Lab65 labA = ColorCast<Lab65>(a);
            const Lab65 labB = ColorCast<Lab65>(b);

            const double dL = labA.l - labB.l;
            const double c1 = Math::Sqrt(labA.a * labA.a + labA.b * labA.b);
            const double c2 = Math::Sqrt(labB.a * labB.a + labB.b * labB.b);

            const double dC = c1 - c2;
            const double dA = labA.a - labB.a;
            const double dB = labA.b - labB.b;

            const double dL2 = dL * dL;
            const double dC2 = dC * dC;
            const double dH2 = dA * dA + dB * dB - dC2;

            const double ksL = kL;
            const double ksC = 1 + k1 * c1;
            const double ksH = 1 + k2 * c1;

            return Math::Sqrt(
                dL2 / (ksL * ksL)
                + dC2 / (ksC * ksC)
                + dH2 / (ksH * ksH)
            );
        }
    };

    inline constexpr CIE94Diff CIE94Diff_GraphicArts{ 1, 0.045, 0.015 };
    inline constexpr CIE94Diff CIE94Diff_Textiles{ 2, 0.048, 0.014 };
}
