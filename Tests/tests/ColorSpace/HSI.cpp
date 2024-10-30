import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HSI")
{
    SECTION("RGB to HSI")
    {
        constexpr RGB rgb{ 0.8, 0.5, 0.25 };
        HSI hsi = ColorCast<HSI>(rgb);
        REQUIRE(hsi.h == 27.0_nearly(1.0));
        REQUIRE(hsi.s == 0.51_nearly(0.01));
        REQUIRE(hsi.i == 0.52_nearly(0.01));
    }
    SECTION("HSI to RGB")
    {
        constexpr HSI hsi{ 27.0, 0.51, 0.52 };
        RGB rgb = ColorCast<RGB>(hsi);

        REQUIRE(rgb.r == 0.8_nearly(0.01));
        REQUIRE(rgb.g == 0.5_nearly(0.01));
        REQUIRE(rgb.b == 0.25_nearly(0.01));
    }
    SECTION("HSI Diff")
    {
        constexpr HSI a{ 360.0, 0.0, 1.0 };
        constexpr HSI b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<HSI>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
}
