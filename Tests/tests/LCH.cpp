import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("LCH")
{
    SECTION("Lab50 to LCH50 to Lab50")
    {
        constexpr Lab50 src{ 120, 0.2, 0.3 };
        const Lab50 dst = ColorCast<Lab50>(ColorCast<LCH50>(src));

        REQUIRE(dst.l == 120_nearly);
        REQUIRE(dst.a == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }

    SECTION("Lab65 to LCH65 to Lab65")
    {
        constexpr Lab65 src{ 120, 0.2, 0.3 };
        const Lab65 dst = ColorCast<Lab65>(ColorCast<LCH65>(src));

        REQUIRE(dst.l == 120_nearly);
        REQUIRE(dst.a == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }
}
