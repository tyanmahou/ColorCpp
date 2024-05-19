import ColorCpp;

#include "catch.hpp"

using namespace colorcpp;

TEST_CASE("CMY")
{
    SECTION("CMY to RGB")
    {
        constexpr CMY cmy{ 1.0, 0.5, 0.3 };
        constexpr RGB rgb = ColorCast<RGB>(cmy);
        REQUIRE(rgb.r == 0.0);
        REQUIRE(rgb.g == 0.5);
        REQUIRE(rgb.b == 0.7);
    }
    SECTION("RGB to CMY")
    {
        constexpr RGB rgb{ 1.0, 0.5, 0.3 };
        constexpr CMY cmy = ColorCast<CMY>(rgb);
        REQUIRE(cmy.c == 0.0);
        REQUIRE(cmy.m == 0.5);
        REQUIRE(cmy.y == 0.7);
    }
}
