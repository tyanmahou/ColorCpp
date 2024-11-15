import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("CIE76")
{
    SECTION("CIE76 Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE76(a, b);
        REQUIRE(diff == 173.20504_nearly(0.001));
    }

    SECTION("CIE76 RGB Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CIE76(
            ColorCast<RGB>(a),
            ColorCast<RGB>(b)
        );
        REQUIRE(diff == 173.20504_nearly(0.001));
    }
}
