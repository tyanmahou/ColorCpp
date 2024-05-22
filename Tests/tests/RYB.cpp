import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("RYB")
{
    SECTION("RGB to RYB")
    {
        {
            constexpr RGB rgb{ 1.0, 1.0, 0.0 };
            constexpr RYB ryb = ColorCast<RYB>(rgb);
            REQUIRE(ryb.r == 0.0_nearly);
            REQUIRE(ryb.y == 1.0_nearly);
            REQUIRE(ryb.b == 0.0_nearly);
        }
        {
            constexpr RGB rgb{ 1.0, 0.0, 0.0 };
            constexpr RYB ryb = ColorCast<RYB>(rgb);
            REQUIRE(ryb.r == 1.0_nearly);
            REQUIRE(ryb.y == 0.0_nearly);
            REQUIRE(ryb.b == 0.0_nearly);
        }
        {
            constexpr RGB rgb{ 0.0, 1.0, 0.0 };
            constexpr RYB ryb = ColorCast<RYB>(rgb);
            REQUIRE(ryb.r == 0.0_nearly);
            REQUIRE(ryb.y == 1.0_nearly);
            REQUIRE(ryb.b == 1.0_nearly);
        }
        {
            constexpr RGB rgb{ 0.0, 0.0, 1.0 };
            constexpr RYB ryb = ColorCast<RYB>(rgb);
            REQUIRE(ryb.r == 0.0_nearly);
            REQUIRE(ryb.y == 0.0_nearly);
            REQUIRE(ryb.b == 1.0_nearly);
        }
    }
    SECTION("RYB to RGB")
    {
        {
            constexpr RYB ryb{ 0.0, 1.0, 0.0 };
            constexpr RGB rgb = ColorCast<RGB>(ryb);

            REQUIRE(rgb.r == 1.0_nearly);
            REQUIRE(rgb.g == 1.0_nearly);
            REQUIRE(rgb.b == 0.0_nearly);
        }
        {
            constexpr RYB ryb{ 1.0, 0.0, 0.0 };
            constexpr RGB rgb = ColorCast<RGB>(ryb);

            REQUIRE(rgb.r == 1.0_nearly);
            REQUIRE(rgb.g == 0.0_nearly);
            REQUIRE(rgb.b == 0.0_nearly);
        }
        {
            constexpr RYB ryb{ 0.0, 1.0, 1.0 };
            constexpr RGB rgb = ColorCast<RGB>(ryb);

            REQUIRE(rgb.r == 0.0_nearly);
            REQUIRE(rgb.g == 1.0_nearly);
            REQUIRE(rgb.b == 0.0_nearly);
        }
        {
            constexpr RYB ryb{ 0.0, 0.0, 1.0 };
            constexpr RGB rgb = ColorCast<RGB>(ryb);

            REQUIRE(rgb.r == 0.0_nearly);
            REQUIRE(rgb.g == 0.0_nearly);
            REQUIRE(rgb.b == 1.0_nearly);
        }
    }
}
