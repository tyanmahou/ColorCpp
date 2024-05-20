import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"

using namespace colorcpp;

TEST_CASE("CMYK")
{
    SECTION("CMYK to CMY")
    {
        constexpr CMYK cmyk{ 1.0, 0.2 / 0.7, 0, 0.3 };
        constexpr CMY cmy = ColorCast<CMY>(cmyk);
        REQUIRE(NearEquals(cmy.c, 1.0));
        REQUIRE(NearEquals(cmy.m, 0.5));
        REQUIRE(NearEquals(cmy.y, 0.3));
    }
    SECTION("CMY to CMYK")
    {
        constexpr CMY cmy{ 1.0, 0.5, 0.3 };
        constexpr CMYK cmyk = ColorCast<CMYK>(cmy);

        REQUIRE(NearEquals(cmyk.k, 0.3));

        REQUIRE(NearEquals(cmyk.c, 1.0));
        REQUIRE(NearEquals(cmyk.m, 0.2 / 0.7));
        REQUIRE(NearEquals(cmyk.y, 0));
    }
    SECTION("CMYK to RGB")
    {
        constexpr CMYK cmyk{ 1.0, 0.2 / 0.7, 0, 0.3 };
        constexpr RGB rgb = ColorCast<RGB>(cmyk);
        REQUIRE(NearEquals(rgb.r, 0.0));
        REQUIRE(NearEquals(rgb.g, 0.5));
        REQUIRE(NearEquals(rgb.b, 0.7));
    }
    SECTION("RGB to CMYK")
    {
        constexpr RGB rgb{ 0.0, 0.5, 0.7 };
        constexpr CMYK cmyk = ColorCast<CMYK>(rgb);

        REQUIRE(NearEquals(cmyk.k, 0.3));

        REQUIRE(NearEquals(cmyk.c, 1.0));
        REQUIRE(NearEquals(cmyk.m, 0.2 / 0.7));
        REQUIRE(NearEquals(cmyk.y, 0));
    }
}
