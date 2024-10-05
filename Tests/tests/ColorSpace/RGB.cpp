import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("RGB")
{
    SECTION("RGBA to RGB")
    {
        constexpr RGBA rgba{ 0.1, 0.2, 0.3, 0.4 };
        constexpr RGB rgb = ColorCast<RGB>(rgba);
        REQUIRE(rgb.r == 0.1);
        REQUIRE(rgb.g == 0.2);
        REQUIRE(rgb.b == 0.3);
    }
    SECTION("RGB to RGBA")
    {
        constexpr RGB rgb{ 0.1, 0.2, 0.3 };
        constexpr RGBA rgba = ColorCast<RGBA>(rgb);
        REQUIRE(rgba.r == 0.1);
        REQUIRE(rgba.g == 0.2);
        REQUIRE(rgba.b == 0.3);
        REQUIRE(rgba.a == 1.0);
    }

    SECTION("RGBA32 to RGB")
    {
        constexpr RGBA32 rgba{ 255, 102, 51, 32 };
        constexpr RGB rgb = ColorCast<RGB>(rgba);
        REQUIRE(rgb.r == 1.0_nearly);
        REQUIRE(rgb.g == 0.4_nearly);
        REQUIRE(rgb.b == 0.2_nearly);
    }
    SECTION("RGB to RGBA32")
    {
        constexpr RGB rgb{ 1.0, 0.4, 0.2 };
        constexpr RGBA32 rgba32 = ColorCast<RGBA32>(rgb);
        REQUIRE(rgba32.r == 255);
        REQUIRE(rgba32.g == 102);
        REQUIRE(rgba32.b == 51);
        REQUIRE(rgba32.a == 255);
    }

    SECTION("RGBA24 to RGB")
    {
        constexpr RGB24 rgba32{ 255, 102, 51 };
        constexpr RGB rgb = ColorCast<RGB>(rgba32);
        REQUIRE(rgb.r == 1.0_nearly);
        REQUIRE(rgb.g == 0.4_nearly);
        REQUIRE(rgb.b == 0.2_nearly);
    }
    SECTION("RGB to RGBA24")
    {
        constexpr RGB rgb{ 1.0, 0.4, 0.2 };
        constexpr RGB24 rgb24 = ColorCast<RGB24>(rgb);
        REQUIRE(rgb24.r == 255);
        REQUIRE(rgb24.g == 102);
        REQUIRE(rgb24.b == 51);
    }
    SECTION("RGB Diff")
    {
        constexpr RGB a{ 1.0, 0.0, 1.0 };
        constexpr RGB b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<RGB>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
