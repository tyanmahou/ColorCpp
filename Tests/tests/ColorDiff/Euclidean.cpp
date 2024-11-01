import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("Euclidean")
{
    SECTION("Euclidean Diff")
    {
        constexpr RGB a{ 1, 0, 1 };
        constexpr RGB b{ 0, 1, 0 };

        const double diff = ColorDiff::Euclidean<RGB>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
