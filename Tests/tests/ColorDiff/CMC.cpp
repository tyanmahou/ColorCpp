﻿import ColorCpp;

#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("CMC")
{
    SECTION("CMC Diff")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CMC(a, b);
        REQUIRE(diff == 102.563_nearly(0.001));
    }
    SECTION("CMC Diff Param")
    {
        constexpr Lab65 a{ 100, 0, 100 };
        constexpr Lab65 b{ 0, 100, 0 };

        const double diff = ColorDiff::CMC(2.0, 1.0)(a, b);
        REQUIRE(diff == 102.563_nearly(0.001));
    }
}
