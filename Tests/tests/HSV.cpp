import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HSV")
{
    SECTION("RGB to HSV")
    {
        constexpr RGB rgb{ 0.8, 0.5, 0.25 };
        HSV hsv = ColorCast<HSV>(rgb);
        REQUIRE(hsv.h == 27.0_nearly(1.0));
        REQUIRE(hsv.s == 0.68_nearly(0.01));
        REQUIRE(hsv.v == 0.80_nearly(0.01));
    }
    SECTION("HSV to RGB")
    {
        constexpr HSV hsv{ 27.0, 0.68, 0.8 };
        RGB rgb = ColorCast<RGB>(hsv);

        REQUIRE(rgb.r == 0.8_nearly(0.01));
        REQUIRE(rgb.g == 0.5_nearly(0.01));
        REQUIRE(rgb.b == 0.25_nearly(0.01));
    }
}
