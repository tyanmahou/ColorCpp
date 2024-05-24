import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HSL")
{
    SECTION("RGB to HSL")
    {
        constexpr RGB rgb{ 0.8, 0.5, 0.25 };
        HSL hsl = ColorCast<HSL>(rgb);
        REQUIRE(hsl.h == 27.0_nearly(1.0));
        REQUIRE(hsl.s == 0.57_nearly(0.01));
        REQUIRE(hsl.l == 0.52_nearly(0.01));
    }
    SECTION("HSL to RGB")
    {
        constexpr HSL hsl{ 27.0, 0.57, 0.52 };
        RGB rgb = ColorCast<RGB>(hsl);

        REQUIRE(rgb.r == 0.8_nearly(0.01));
        REQUIRE(rgb.g == 0.5_nearly(0.01));
        REQUIRE(rgb.b == 0.25_nearly(0.01));
    }
}
