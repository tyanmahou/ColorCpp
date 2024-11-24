import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

namespace
{
    struct MyRGB
    {
        float r;
        float g;
        float b;
    };
}

namespace colorcpp
{
    template<>
    struct ColorCastDependency<MyRGB>
    {
        using depend_type = RGB;
    };
    template<>
    struct ColorCastTraits<MyRGB, RGB>
    {
        [[nodiscard]] constexpr static MyRGB Cast(const RGB& from)
        {
            const auto& [r, g, b] = from;
            return {
                static_cast<float>(r),
                static_cast<float>(g),
                static_cast<float>(b),
            };
        }
    };
    template<>
    struct ColorCastTraits<RGB, MyRGB>
    {
        [[nodiscard]] constexpr static RGB Cast(const MyRGB& from)
        {
            const auto& [r, g, b] = from;
            return {
                static_cast<double>(r),
                static_cast<double>(g),
                static_cast<double>(b),
            };
        }
    };

    // Euclidean Diff
    template<>
    struct ColorDiffTrait<MyRGB>
    {
        [[nodiscard]] static double Diff(const MyRGB& left, const MyRGB& right)
        {
            const float r = left.r - right.r;
            const float g = left.g - right.g;
            const float b = left.b - right.b;
            return std::sqrt(static_cast<double>(r * r + g * g + b * b));
        }
    };
}
TEST_CASE("Custom")
{
    SECTION("RGB to MyRGB")
    {
        {
            constexpr RGB src{ 0.0, 0.0, 0.0 };
            const auto dst = ColorCast<MyRGB>(src);

            REQUIRE(dst.r == 0_nearly);
            REQUIRE(dst.g == 0_nearly);
            REQUIRE(dst.b == 0_nearly);
        }
        {
            constexpr RGB src{ 1.0, 1.0, 1.0 };
            const auto dst = ColorCast<MyRGB>(src);

            REQUIRE(dst.r == 1_nearly);
            REQUIRE(dst.g == 1_nearly);
            REQUIRE(dst.b == 1_nearly);
        }
        {
            constexpr RGB src{ 0.1, 0.5, 0.9 };
            const auto dst = ColorCast<MyRGB>(src);

            REQUIRE(dst.r == 0.1_nearly);
            REQUIRE(dst.g == 0.5_nearly);
            REQUIRE(dst.b == 0.9_nearly);
        }
    }
    SECTION("Euclidean Diff")
    {
        constexpr MyRGB a{ 1, 0, 1 };
        constexpr MyRGB b{ 0, 1, 0 };

        const double diff = ColorDiff::Euclidean(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
