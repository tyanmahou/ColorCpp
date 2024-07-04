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

    SECTION("RGB to Prophoto")
    {
        {
            constexpr RGB src{ 0.0, 0.0, 0.0 };
            const auto dst = ColorCast<Prophoto>(src);

            REQUIRE(dst.r == 0_nearly);
            REQUIRE(dst.g == 0_nearly);
            REQUIRE(dst.b == 0_nearly);
        }
        {
            constexpr RGB src{ 1.0, 1.0, 1.0 };
            const auto dst = ColorCast<Prophoto>(src);

            REQUIRE(dst.r == 1_nearly);
            REQUIRE(dst.g == 1_nearly);
            REQUIRE(dst.b == 1_nearly);
        }
        {
            constexpr RGB src{ 0.1, 0.5, 0.9 };
            const auto dst = ColorCast<Prophoto>(src);

            REQUIRE(dst.r == 0.393_nearly(0.01));
            REQUIRE(dst.g == 0.420_nearly(0.01));
            REQUIRE(dst.b == 0.824_nearly(0.01));
        }
    }
}
