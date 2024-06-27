import ColorCpp;
#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("A98")
{
    SECTION("XYZ65 to A98 to XYZ65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<A98>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
}
