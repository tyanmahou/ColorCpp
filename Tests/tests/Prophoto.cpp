import ColorCpp;
#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("Prophoto")
{
    SECTION("XYZ50 to Prophoto to XYZ50")
    {
        constexpr XYZ50 src{ 0.1, 0.2, 0.3 };
        const XYZ50 dst = ColorCast<XYZ50>(ColorCast<Prophoto>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
}
