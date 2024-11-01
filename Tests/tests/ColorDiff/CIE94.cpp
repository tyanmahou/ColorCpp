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

        const double diff = ColorDiff::CIE94<GraphicArts>(a, b);
        REQUIRE(diff == 114.891_nearly(0.001));
    }
    SECTION("CIE94 Textiles Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE94<Textiles>(a, b);
        REQUIRE(diff == 77.280_nearly(0.001));
    }
}
