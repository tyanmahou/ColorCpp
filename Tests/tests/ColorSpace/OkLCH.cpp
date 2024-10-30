import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("OkLCH")
{
    SECTION("OkLab to OkLCH to OkLab")
    {
        constexpr OkLab src{ 0.1, 0.2, 0.3 };
        const OkLab dst = ColorCast<OkLab>(ColorCast<OkLCH>(src));

        REQUIRE(dst.l == 0.1_nearly);
        REQUIRE(dst.a == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }
    SECTION("OkLCH Diff")
    {
        constexpr OkLCH a{ 1.0, 0.0, 360.0 };
        constexpr OkLCH b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<OkLCH>(a, b);
        REQUIRE(diff == 1.4142135624_nearly);
    }
}
