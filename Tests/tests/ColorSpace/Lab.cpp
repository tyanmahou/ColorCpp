import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("Lab")
{
    SECTION("RGB to Lab50 to RGB")
    {
        constexpr RGB src{ 0.1, 0.2, 0.3 };
        const RGB dst = ColorCast<RGB>(ColorCast<Lab50>(src));

        REQUIRE(dst.r == 0.1_nearly);
        REQUIRE(dst.g == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }

    SECTION("RGB to Lab65 to RGB")
    {
        constexpr RGB src{ 0.1, 0.2, 0.3 };
        const RGB dst = ColorCast<RGB>(ColorCast<Lab65>(src));

        REQUIRE(dst.r == 0.1_nearly);
        REQUIRE(dst.g == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }
    SECTION("Lab50 Diff")
    {
        constexpr Lab50 a{ 1.0, 0.0, 1.0 };
        constexpr Lab50 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<Lab50>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
    SECTION("Lab65 Diff")
    {
        constexpr Lab65 a{ 1.0, 0.0, 1.0 };
        constexpr Lab65 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<Lab65>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
