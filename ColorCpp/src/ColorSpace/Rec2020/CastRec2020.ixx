export module ColorCpp:CastRec2020;
import :ColorCastTrait;

import :Rec2020;
import :XYZ;
import :Math;

namespace
{
    using namespace colorcpp;
    constexpr double alpha = 1.09929682680944;
    constexpr double beta = 0.018053968510807;
    [[nodiscard]] inline constexpr double Gamma(double v)
    {
        const double sign = (v >= 0 ? 1.0 : -1.0);
        if (double abs = Math::Abs(v);  abs >= beta) {
            return sign * (alpha * Math::Pow(abs, 0.45) - (alpha - 1));
        }
        return 4.5 * v;
    }
    [[nodiscard]] inline constexpr double Linearlize(double v)
    {
        const double sign = (v >= 0 ? 1.0 : -1.0);
        if (double abs = Math::Abs(v); abs >= beta * 4.5) {
            return sign * Math::Pow((abs + alpha - 1) / alpha, 1 / 0.45);
        }
        return v / 4.5;
    }
}
export namespace colorcpp
{
    template<>
    struct ColorCastDependency<Rec2020>
    {
        using depend_type = XYZ;
    };

    // Rec2020 <=> XYZ
    template<>
    struct ColorCastTraits<Rec2020, XYZ>
    {
        [[nodiscard]] constexpr static Rec2020 Cast(const XYZ& xyz)
        {
            const auto& [x, y, z] = xyz;
            double r = 1.7166511879712683 * x - 0.3556707837763925 * y - 0.2533662813736599 * z;
            double g = -0.6666843518324893 * x + 1.6164812366349395 * y + 0.0157685458139111 * z;
            double b = 0.0176398574453108 * x - 0.0427706132578085 * y + 0.9421031212354739 * z;
            return {
                .r = ::Gamma(r),
                .g = ::Gamma(g),
                .b = ::Gamma(b),
            };
        }
    };
    template<>
    struct ColorCastTraits<XYZ, Rec2020>
    {
        [[nodiscard]] constexpr static XYZ Cast(const Rec2020& rgb)
        {
            double r = ::Linearlize(rgb.r);
            double g = ::Linearlize(rgb.g);
            double b = ::Linearlize(rgb.b);
            return {
                .x = 0.6369580483012911 * r + 0.1446169035862083 * g + 0.1688809751641721 * b,
                .y = 0.262700212011267  * r + 0.6779980715188708 * g + 0.059301716469862 * b,
                .z = 0.0280726930490874 * g + 1.0609850577107909 * b,
            };
        }
    };
}
