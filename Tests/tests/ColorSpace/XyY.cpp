import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("XyY")
{
    SECTION("XYZ65 to XyY65 to XYZ65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<XyY65>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
    SECTION("XYZ50 to XyY50 to XYZ50")
    {
        constexpr XYZ50 src{ 0.1, 0.2, 0.3 };
        const XYZ50 dst = ColorCast<XYZ50>(ColorCast<XyY50>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
    SECTION("XyY50 Diff")
    {
        constexpr XyY50 a{ 1.0, 0.0, 1.0 };
        constexpr XyY50 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<XyY50>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
    SECTION("XyY65 Diff")
    {
        constexpr XyY65 a{ 1.0, 0.0, 1.0 };
        constexpr XyY65 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<XyY65>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
