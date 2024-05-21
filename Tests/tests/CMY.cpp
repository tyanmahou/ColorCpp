import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
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
}
