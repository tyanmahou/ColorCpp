import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("YIQ")
{
    SECTION("RGB to YIQ to RGB")
    {
        constexpr RGB src{ 0.1, 0.2, 0.3 };
        const RGB dst = ColorCast< RGB>(ColorCast<YIQ>(src));

        REQUIRE(dst.r == 0.1_nearly);
        REQUIRE(dst.g == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }
    SECTION("RGB to YIQ")
    {
        {
            constexpr RGB src{ 0.0, 0.0, 0.0 };
            const auto dst = ColorCast<YIQ>(src);

            REQUIRE(dst.y == 0_nearly);
            REQUIRE(dst.i == 0_nearly);
            REQUIRE(dst.q == 0_nearly);
        }
        {
            constexpr RGB src{ 1.0, 1.0, 1.0 };
            const auto dst = ColorCast<YIQ>(src);

            REQUIRE(dst.y == 1_nearly);
            REQUIRE(dst.i == 0_nearly);
            REQUIRE(dst.q == 0_nearly);
        }
    }
}
