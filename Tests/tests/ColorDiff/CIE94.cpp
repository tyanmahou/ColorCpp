import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("CIE94")
{
    SECTION("CIE94 Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE94(a, b);
        REQUIRE(diff == 114.891_nearly(0.001));
    }
    SECTION("CIE94 GraphicArts Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE94_GraphicArts(a, b);
        REQUIRE(diff == 114.891_nearly(0.001));

        REQUIRE(diff == ColorDiff::CIE94<1.0, 0.045, 0.015>(a, b));
    }
    SECTION("CIE94 Textiles Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE94_Textiles(a, b);
        REQUIRE(diff == 77.280_nearly(0.001));
        REQUIRE(diff == ColorDiff::CIE94<2.0, 0.048, 0.014>(a, b));
    }
}
