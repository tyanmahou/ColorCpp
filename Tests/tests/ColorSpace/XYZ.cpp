import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("XYZ")
{
    SECTION("LRGB to XYZ to LRGB")
    {
        constexpr LRGB src{ 0.1, 0.2, 0.3 };
        const LRGB dst = ColorCast<LRGB>(ColorCast<XYZ>(src));

        REQUIRE(dst.r == 0.1_nearly);
        REQUIRE(dst.g == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }

    SECTION("D65 to D50 to D65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<XYZ50>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }

    SECTION("D65 to D50 with LRGB")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ50 dst = ColorCast<XYZ50>(src);
        const XYZ50 dst2 = ColorCast<XYZ50>(ColorCast<LRGB>(src));

        REQUIRE(dst.x == NearlyDouble{ dst2.x });
        REQUIRE(dst.y == NearlyDouble{ dst2.y });
        REQUIRE(dst.z == NearlyDouble{ dst2.z });
    }
}
