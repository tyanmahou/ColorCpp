import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("Luv")
{
    SECTION("XYZ50 to Luv50 to XYZ50")
    {
        constexpr XYZ50 src{ 0.1, 0.2, 0.3 };
        const XYZ50 dst = ColorCast<XYZ50>(ColorCast<Luv50>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }

    SECTION("XYZ65 to Luv65 to XYZ65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<Luv65>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
    SECTION("Luv50 Diff")
    {
        constexpr Luv50 a{ 1.0, 0, 1.0 };
        constexpr Luv50 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<Luv50>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
    SECTION("Luv65 Diff")
    {
        constexpr Luv65 a{ 1.0, 0, 1.0 };
        constexpr Luv65 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<Luv65>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
