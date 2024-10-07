import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("CMY")
{
    SECTION("CMY to RGB")
    {
        constexpr CMY cmy{ 1.0, 0.5, 0.3 };
        constexpr RGB rgb = ColorCast<RGB>(cmy);

        REQUIRE(rgb.r == 0.0_nearly);
        REQUIRE(rgb.g == 0.5_nearly);
        REQUIRE(rgb.b == 0.7_nearly);
    }
    SECTION("RGB to CMY")
    {
        constexpr RGB rgb{ 1.0, 0.5, 0.3 };
        constexpr CMY cmy = ColorCast<CMY>(rgb);
        REQUIRE(cmy.c == 0.0_nearly);
        REQUIRE(cmy.m == 0.5_nearly);
        REQUIRE(cmy.y == 0.7_nearly);
    }
    SECTION("CMY Diff")
    {
        constexpr CMY a{ 1.0, 0.0, 1.0 };
        constexpr CMY b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<CMY>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
