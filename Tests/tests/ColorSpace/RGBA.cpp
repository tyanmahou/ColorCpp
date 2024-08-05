import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("RGBA")
{
    SECTION("RGBA32 to RGBA")
    {
        constexpr RGBA32 rgba32{ 255, 102, 51, 153 };
        constexpr RGBA rgba = ColorCast<RGBA>(rgba32);
        REQUIRE(rgba.r == 1.0_nearly);
        REQUIRE(rgba.g == 0.4_nearly);
        REQUIRE(rgba.b == 0.2_nearly);
        REQUIRE(rgba.a == 0.6_nearly);
    }
    SECTION("RGB24 to RGBA32")
    {
        constexpr RGBA rgba{ 1.0, 0.4, 0.2, 0.6 };
        constexpr RGBA32 rgba32 = ColorCast<RGBA32>(rgba);
        REQUIRE(rgba32.r == 255);
        REQUIRE(rgba32.g == 102);
        REQUIRE(rgba32.b == 51);
        REQUIRE(rgba32.a == 153);
    }
}
