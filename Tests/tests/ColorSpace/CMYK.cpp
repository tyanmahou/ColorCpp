import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"

using namespace colorcpp;

TEST_CASE("CMYK")
{
    SECTION("CMYK to CMY")
    {
        constexpr CMYK cmyk{ 1.0, 0.2 / 0.7, 0, 0.3 };
        constexpr CMY cmy = ColorCast<CMY>(cmyk);
        REQUIRE(cmy.c == 1.0_nearly);
        REQUIRE(cmy.m == 0.5_nearly);
        REQUIRE(cmy.y == 0.3_nearly);
    }
    SECTION("CMY to CMYK")
    {
        constexpr CMY cmy{ 1.0, 0.5, 0.3 };
        constexpr CMYK cmyk = ColorCast<CMYK>(cmy);

        REQUIRE(cmyk.k == 0.3_nearly);

        REQUIRE(cmyk.c == 1.0_nearly);
        REQUIRE(cmyk.m == NearlyDouble{ 0.2 / 0.7 });
        REQUIRE(cmyk.y == 0.0_nearly);
    }
    SECTION("CMYK to RGB")
    {
        constexpr CMYK cmyk{ 1.0, 0.2 / 0.7, 0, 0.3 };
        constexpr RGB rgb = ColorCast<RGB>(cmyk);
        REQUIRE(rgb.r == 0.0_nearly);
        REQUIRE(rgb.g == 0.5_nearly);
        REQUIRE(rgb.b == 0.7_nearly);
    }
    SECTION("RGB to CMYK")
    {
        constexpr RGB rgb{ 0.0, 0.5, 0.7 };
        constexpr CMYK cmyk = ColorCast<CMYK>(rgb);

        REQUIRE(cmyk.k == 0.3_nearly);

        REQUIRE(cmyk.c == 1.0_nearly);
        REQUIRE(cmyk.m == 0.2 / 0.7_nearly);
        REQUIRE(cmyk.y == 0_nearly);
    }
    SECTION("CMYK Diff")
    {
        constexpr CMYK a{ 1.0, 0.0, 1.0, 0 };
        constexpr CMYK b{ 0, 1.0, 0, 1.0 };

        const double diff = ColorDiff::Euclidean<CMYK>(a, b);
        REQUIRE(diff == 2.0_nearly);
    }
}
