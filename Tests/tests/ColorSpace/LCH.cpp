import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
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
    SECTION("LCH50 Diff")
    {
        constexpr LCH50 a{ 1.0, 0.0, 360.0 };
        constexpr LCH50 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<LCH50>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
    SECTION("LCH65 Diff")
    {
        constexpr LCH65 a{ 1.0, 0.0, 360.0 };
        constexpr LCH65 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<LCH65>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
}
