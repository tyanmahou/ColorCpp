import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HSL")
{
    SECTION("RGB to HSL Cylinder")
    {
        constexpr RGB rgb{ 0.8, 0.5, 0.25 };
        HSLCylinder hsl = ColorCast<HSLCylinder>(rgb);
        REQUIRE(hsl.h == 27.0_nearly(1.0));
        REQUIRE(hsl.s == 0.57_nearly(0.01));
        REQUIRE(hsl.l == 0.52_nearly(0.01));
    }
    SECTION("HSL Cylinder to RGB")
    {
        constexpr HSLCylinder hsl{ 27.0, 0.57, 0.52 };
        RGB rgb = ColorCast<RGB>(hsl);

        REQUIRE(rgb.r == 0.8_nearly(0.01));
        REQUIRE(rgb.g == 0.5_nearly(0.01));
        REQUIRE(rgb.b == 0.25_nearly(0.01));
    }

    SECTION("RGB to HSL Cone")
    {
        constexpr RGB rgb{ 0.8, 0.5, 0.25 };
        HSLCone hsl = ColorCast<HSLCone>(rgb);
        REQUIRE(hsl.h == 27.0_nearly(1.0));
        REQUIRE(hsl.s == 0.55_nearly(0.01));
        REQUIRE(hsl.l == 0.52_nearly(0.01));
    }
    SECTION("HSL Cone to RGB")
    {
        constexpr HSLCone hsl{ 27.0, 0.55, 0.52 };
        RGB rgb = ColorCast<RGB>(hsl);

        REQUIRE(rgb.r == 0.8_nearly(0.01));
        REQUIRE(rgb.g == 0.5_nearly(0.01));
        REQUIRE(rgb.b == 0.25_nearly(0.01));
    }
    SECTION("HSL Cylinder Diff")
    {
        constexpr HSLCylinder a{ 360.0, 0.0, 1.0 };
        constexpr HSLCylinder b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<HSLCylinder>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
    SECTION("HSL Cone Diff")
    {
        constexpr HSLCone a{ 360.0, 0.0, 1.0 };
        constexpr HSLCone b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<HSLCone>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
}
