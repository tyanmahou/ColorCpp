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
            const auto[l1, a1, b1] = ColorCast<Lab65>(a);
            const auto [l2, a2, b2] = ColorCast<Lab65>(b);

            const double c1 = Math::Sqrt(a1 * a1 + b1 * b1);
            const double c2 = Math::Sqrt(a2 * a2 + b2 * b2);

            const double cm = (c1 + c2) / 2.0;
            const double cm7 = Math::Pow7(cm);

            const double g = 0.5 * (1 - Math::Sqrt(cm7 / (cm7 + 6103515625.0)));
            const double a1p = a1 * (1 + g);
            const double a2p = a2 * (1 + g);

            const double c1p = Math::Sqrt(a1p * a1p + b1 * b1);
            const double c2p = Math::Sqrt(a2p * a2p + b2 * b2);

            double h1p = Math::Atan2(b1, a1p);
            if (h1p < 0) {
                h1p += Math::TwoPi;
            }
            double h2p = Math::Atan2(b2, a2p);
            if (h2p < 0) {
                h2p += Math::TwoPi;
            }

            const double deltaL = l2 - l1;
            const double deltaCp = c2p - c1p;
            double deltaHp = c2p - c1p;
            if (deltaHp > Math::Pi) {
                deltaHp -= Math::TwoPi;
            } else if (deltaHp < -Math::Pi) {
                deltaHp += Math::TwoPi;
            }
            const double deltaH = 2 * Math::Sqrt(c1p * c2p) * Math::Sin(deltaHp / 2.0);

            const double lm = (l1 + l2) / 2.0;
            const double cpm = (c1p + c2p) / 2.0;
            double hm;
            if (c1p * c2p == 0) {
                hm = h1p + h2p;
            } else {
                hm = (h1p + h2p) / 2;
                if (Math::Abs(h1p - h2p) > Math::Pi) {
                    hm -= Math::Pi;
                }
                if (hm < 0) {
                    hm += Math::TwoPi;
                }
            }
            const double t = 1
                - 0.17 * Math::Cos(hm - Math::Pi / 6)
                + 0.24 * Math::Cos(2 * hm)
                + 0.32 * Math::Cos(3 * hm + Math::Pi / 30)
                - 0.20 * Math::Cos(4 * hm - (63 * Math::Pi) / 180);

            const double lm50_2 = Math::Pow(lm - 50, 2);
            const double sL = 1 + (0.015 * lm50_2) / Math::Sqrt(20 + lm50_2);
            const double sC = 1 + 0.045 * cpm;
            const double sH = 1 + 0.015 * cpm * t;

            const double cpm7 = Math::Pow7(cm);
            const double rC = 2 * Math::Sqrt(cpm7 / (cpm7 + 6103515625.0));

            const double deltaTheta = 30 * Math::Exp(-1 * Math::Pow2(((180 / Math::Pi) * hm - 275) / 25));
            const double rT = -Math::SinDeg(2 * deltaTheta) * rC;
            return Math::Sqrt(
                Math::Pow2(deltaL / (kL * sL))
                + Math::Pow2(deltaCp / (kC * sC))
                + Math::Pow2(deltaH / (kH * sH))
                + (((rT * deltaCp) / (kC * sC)) * deltaH) / (kH * sH)
            );
        }
    };
}
