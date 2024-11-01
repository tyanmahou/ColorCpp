﻿import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("ITP")
{
    SECTION("RGB to ITP to RGB")
    {
        constexpr RGB src{ 0.1, 0.2, 0.3 };
        const RGB dst = ColorCast<RGB>(ColorCast<ITP>(src));

        REQUIRE(dst.r == 0.1_nearly);
        REQUIRE(dst.g == 0.2_nearly);
        REQUIRE(dst.b == 0.3_nearly);
    }
    SECTION("ITP Diff")
    {
        constexpr ITP a{ 1.0, 0.0, 1.0 };
        constexpr ITP b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<ITP>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
