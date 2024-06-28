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

    SECTION("RGB to A98")
    {
        {
            constexpr RGB src{ 0.0, 0.0, 0.0 };
            const auto dst = ColorCast<A98>(src);

            REQUIRE(dst.r == 0_nearly);
            REQUIRE(dst.g == 0_nearly);
            REQUIRE(dst.b == 0_nearly);
        }
        {
            constexpr RGB src{ 1.0, 1.0, 1.0 };
            const auto dst = ColorCast<A98>(src);

            REQUIRE(dst.r == 1_nearly);
            REQUIRE(dst.g == 1_nearly);
            REQUIRE(dst.b == 1_nearly);
        }
        {
            constexpr RGB src{ 0.1, 0.5, 0.9 };
            const auto dst = ColorCast<A98>(src);

            REQUIRE(dst.r == 0.294_nearly(0.01));
            REQUIRE(dst.g == 0.496_nearly(0.01));
            REQUIRE(dst.b == 0.884_nearly(0.01));
        }
    }
}
