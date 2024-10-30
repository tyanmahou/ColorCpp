﻿import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HunterLab")
{
    SECTION("XYZ50 to HunterLab50 to XYZ50")
    {
        constexpr XYZ50 src{ 0.1, 0.2, 0.3 };
        const XYZ50 dst = ColorCast<XYZ50>(ColorCast<HunterLab50>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }

    SECTION("XYZ65 to HunterLab65 to XYZ65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<HunterLab65>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }
    SECTION("HunterLab50 Diff")
    {
        constexpr HunterLab50 a{ 1.0, 0.0, 1.0 };
        constexpr HunterLab50 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<HunterLab50>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
    SECTION("HunterLab65 Diff")
    {
        constexpr HunterLab65 a{ 1.0, 0.0, 1.0 };
        constexpr HunterLab65 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<HunterLab65>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
