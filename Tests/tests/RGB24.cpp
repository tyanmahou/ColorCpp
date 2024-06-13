import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("RGB24")
{
    SECTION("RGBA to RGB24")
    {
        constexpr RGBA rgba{ 1.0, 0.4, 0.2, 0.5 };
        constexpr RGB24 rgb = ColorCast<RGB24>(rgba);
        REQUIRE(rgb.r == 255);
        REQUIRE(rgb.g == 102);
        REQUIRE(rgb.b == 51);
    }
    SECTION("RGB24 to RGBA")
    {
        constexpr RGB24 rgb{ 255, 102, 51 };
        constexpr RGBA rgba = ColorCast<RGBA>(rgb);
        REQUIRE(rgba.r == 1.0);
        REQUIRE(rgba.g == 0.4);
        REQUIRE(rgba.b == 0.2);
        REQUIRE(rgba.a == 1.0);
    }

    SECTION("RGBA32 to RGB24")
    {
        constexpr RGBA32 rgba{ 255, 102, 51, 32 };
        constexpr RGB24 rgb = ColorCast<RGB24>(rgba);
        REQUIRE(rgb.r == 255);
        REQUIRE(rgb.g == 102);
        REQUIRE(rgb.b == 51);
    }
    SECTION("RGB24 to RGBA32")
    {
        constexpr RGB24 rgb{ 255, 102, 51 };
        constexpr RGBA32 rgba32 = ColorCast<RGBA32>(rgb);
        REQUIRE(rgba32.r == 255);
        REQUIRE(rgba32.g == 102);
        REQUIRE(rgba32.b == 51);
        REQUIRE(rgba32.a == 255);
    }
}
