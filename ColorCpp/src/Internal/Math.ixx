export module ColorCpp:Math;
import <algorithm>;
import <cmath>;
import <numbers>;

export namespace colorcpp
{
    class Math
    {
    public:
        static constexpr double Pi = std::numbers::pi;
        static constexpr double TwoPi = std::numbers::pi * 2.0;

        [[nodiscard]] static constexpr inline double Min(double x, double y) noexcept
        {
            return std::min(x, y);
        }
        [[nodiscard]] static constexpr inline double Max(double x, double y) noexcept
        {
            return std::max(x, y);
        }
        [[nodiscard]] static constexpr inline double Min(double x, double y, double z) noexcept
        {
            return std::min(x, std::min(y, z));
        }
        [[nodiscard]] static constexpr inline double Max(double x, double y, double z) noexcept
        {
            return std::max(x, std::max(y, z));
        }
        [[nodiscard]] static constexpr inline double Clamp(double x, double min, double max)
        {
            return std::clamp(x, min, max);
        }
        [[nodiscard]] static constexpr inline double Saturate(double x)
        {
            return Clamp(x, 0.0, 1.0);
        }
        [[nodiscard]] static constexpr inline double Sign(double x) noexcept
        {
            return static_cast<double>((0.0 < x) - (x < 0.0));
        }
        // TODO: C++23でconstexpr対応
        [[nodiscard]] static constexpr inline double Abs(auto x) noexcept
        {
            return std::abs(x);
        }

        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Sqrt(auto x) noexcept
        {
            return std::sqrt(x);
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Pow(auto x, auto y) noexcept
        {
            return std::pow(x, y);
        }
        [[nodiscard]] static constexpr inline double Pow2(double x) noexcept
        {
            return x * x;
        }
        [[nodiscard]] static constexpr inline double Pow3(double x) noexcept
        {
            return x * x * x;
        }
        [[nodiscard]] static constexpr inline double Pow4(double x) noexcept
        {
            return x * x * x * x;
        }
        [[nodiscard]] static constexpr inline double Pow5(double x) noexcept
        {
            return x * x * x * x * x;
        }
        [[nodiscard]] static constexpr inline double Pow6(double x) noexcept
        {
            return x * x * x * x * x * x;
        }
        [[nodiscard]] static constexpr inline double Pow7(double x) noexcept
        {
            return x * x * x * x * x * x * x;
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Cbrt(auto x) noexcept
        {
            return std::cbrt(x);
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Exp(auto x) noexcept
        {
            return std::exp(x);
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Sin(auto x) noexcept
        {
            return std::sin(x);
        }
        [[nodiscard]] static constexpr inline double SinDeg(double x) noexcept
        {
            return Sin(x * Pi / 180.0);
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Cos(auto x) noexcept
        {
            return std::cos(x);
        }
        [[nodiscard]] static constexpr inline double CosDeg(double x) noexcept
        {
            return Cos(x * Pi / 180.0);
        }
        // TODO: C++26でconstexpr対応
        [[nodiscard]] static constexpr inline double Atan2(auto y, auto x) noexcept
        {
            if (y == 0 && x == 0) {
                return 0;
            }
            return std::atan2(y, x);
        }

        // TODO: C++23でconstexpr対応
        [[nodiscard]] static constexpr inline double Fmod(auto x, auto y) noexcept
        {
            return std::fmod(x, y);
        }
        [[nodiscard]] static constexpr inline double Repeat(auto x, auto y) noexcept
        {
            return std::fmod(std::fmod(x, y) + y, y);
        }
        // TODO: C++23でconstexpr対応
        [[nodiscard]] static constexpr double Fraction(auto x) noexcept
        {
            return (x - std::floor(x));
        }
    };
}
