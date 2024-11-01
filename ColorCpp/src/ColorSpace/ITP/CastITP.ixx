export module ColorCpp:CastITP;
import :ColorCastTrait;
import :LRGB;
import :ITP;
import :Math;

namespace
{
    using colorcpp::Math;

    inline constexpr double c1 = 0.8359375;
    inline constexpr double c2 = 18.8515625;
    inline constexpr double c3 = 18.6875;
    inline constexpr double m1 = 0.1593017578125;
    inline constexpr double m2 = 78.84375;

    // PQカーブの適用 EOTF-1
    [[nodiscard]] inline constexpr double PQ(double value)
    {
        double c = Math::Pow(value, m1);
        return Math::Pow((c1 + c2 * c) / (1 + c3 * c), m2);
    }
    [[nodiscard]] inline constexpr double PQInv(double value)
    {
        double c = Math::Pow(value, 1 / m2);
        return Math::Pow((c - c1) / (c2 - c3 * c), 1 / m1);
    }
}
export namespace colorcpp
{
    template<>
    struct ColorCastDependency<ITP>
    {
        using depend_type = LRGB;
    };

    // ITP <=> LRGB
    template<>
    struct ColorCastTraits<ITP, LRGB>
    {
        [[nodiscard]] constexpr static ITP Cast(const LRGB& rgb)
        {
            const auto& [r, g, b] = rgb;
            const double l = (1688 * r + 2146 * g + 262 * b) / 4096.0;
            const double m = (683 * r + 2951 * g + 462 * b) / 4096.0;
            const double s = (99 * r + 309 * g + 3688 * b) / 4096.0;

            const double l_ = ::PQ(l);
            const double m_ = ::PQ(m);
            const double s_ = ::PQ(s);

            const double i = (2048 * l_ + 2048 * m_ + 0 * s_) / 4096.0;
            const double t = (6610 * l_ -13613 * m_ + 7003 * s_) / 4096.0;
            const double p = (17933 * l_  -17390 * m_ -543 * s_) / 4096.0;
            return {i, t, p};
        }
    };
    template<>
    struct ColorCastTraits<LRGB, ITP>
    {
        [[nodiscard]] constexpr static LRGB Cast(const ITP& itp)
        {
            const auto& [i, t, p] = itp;

            const double l_ = i + 0.008609037037933 * t + 0.11102962500303 * p;
            const double m_ = i - 0.008609037037933 * t - 0.11102962500303 * p;
            const double s_ = i + 0.56003133571068 * t - 0.32062717498732 * p;

            const double l = ::PQInv(l_);
            const double m = ::PQInv(m_);
            const double s = ::PQInv(s_);

            const double r = 3.4366066943331 * l - 2.5064521186563 * m + 0.069845424323191 * s;
            const double g = -0.79132955559893 * l + 1.9836004517923 * m - 0.19227089619336 * s;
            const double b = -0.025949899690593 * l - 0.098913714711726 * m + 1.1248636144023 * s;
            return {r, g, b};
        }
    };
}
