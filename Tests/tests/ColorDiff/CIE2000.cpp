import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("CIE2000")
{
    SECTION("CIE2000 Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE2000(a, b);
        REQUIRE(diff == 100.0000_nearly(0.001));
    }
    SECTION("CIE2000 RGB Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE2000(
            ColorCast<RGB>(a),
            ColorCast<RGB>(b)
        );
        REQUIRE(diff == 100.0000_nearly(0.001));
    }
}
