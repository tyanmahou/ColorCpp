export module ColorCpp:CastProphoto;
import :ColorCastTrait;

import :Prophoto;
import :XYZ;
import :Math;

namespace
{
    using namespace colorcpp;
    [[nodiscard]] inline constexpr double Gamma(double v)
    {
        if (double abs = Math::Abs(v);  abs >= 1 / 512.0) {
            return Math::Sign(v) * Math::Pow(abs, 1 / 1.8);
        }
        return 16.0 * v;
    }
    [[nodiscard]] inline constexpr double Linearlize(double v)
    {
        if (double abs = Math::Abs(v);  abs >= 16 / 512.0) {
            return Math::Sign(v) * Math::Pow(abs, 1.8);
        }
        return v / 16.0;
    }
}
export namespace colorcpp
{
    template<>
    struct ColorCastDependency<Prophoto>
    {
        using depend_type = XYZ50;
    };

    // Prophoto <=> XYZ
    template<>
    struct ColorCastTraits<Prophoto, XYZ50>
    {
        [[nodiscard]] constexpr static Prophoto Cast(const XYZ50& xyz)
        {
            const auto& [x, y, z] = xyz;
            double r = 1.3457868816471585 * x - 0.2555720873797946 * y - 0.0511018649755453 * z;
            double g = -0.5446307051249019 * x + 1.5082477428451466 * y + 0.0205274474364214 * z;
            double b = 1.2119675456389452 * z;
            return {
                .r = ::Gamma(r),
                .g = ::Gamma(g),
                .b = ::Gamma(b),
            };
        }
    };
    template<>
    struct ColorCastTraits<XYZ50, Prophoto>
    {
        [[nodiscard]] constexpr static XYZ50 Cast(const Prophoto& rgb)
        {
            double r = ::Linearlize(rgb.r);
            double g = ::Linearlize(rgb.g);
            double b = ::Linearlize(rgb.b);
            return {
                .x = 0.7977666449006423 * r +0.1351812974005331 * g +0.0313477341283922 * b,
                .y = 0.2880748288194013 * r +0.7118352342418731 * g +0.0000899369387256 * b,
                .z = 0.8251046025104602 * b,
            };
        }
    };
}
