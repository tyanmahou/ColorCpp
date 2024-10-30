import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("RGBA32")
{
    SECTION("RGBA32 Diff")
    {
        constexpr RGBA32 a{ 255, 0, 255, 0 };
        constexpr RGBA32 b{ 0, 255, 0, 255 };

        const double diff = ColorDiff::Euclidean<RGBA32>(a, b);
        REQUIRE(diff == 255 * 2.0_nearly);
    }
}
