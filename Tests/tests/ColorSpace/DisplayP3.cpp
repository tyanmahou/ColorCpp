import ColorCpp;
#include "../catch.hpp"
#include "../TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("DisplayP3")
{
    SECTION("XYZ65 to DisplayP3 to XYZ65")
    {
        constexpr XYZ65 src{ 0.1, 0.2, 0.3 };
        const XYZ65 dst = ColorCast<XYZ65>(ColorCast<DisplayP3>(src));

        REQUIRE(dst.x == 0.1_nearly);
        REQUIRE(dst.y == 0.2_nearly);
        REQUIRE(dst.z == 0.3_nearly);
    }

    SECTION("RGB to DisplayP3")
    {
        {
            constexpr RGB src{ 0.0, 0.0, 0.0 };
            const auto dst = ColorCast<DisplayP3>(src);

            REQUIRE(dst.r == 0_nearly);
            REQUIRE(dst.g == 0_nearly);
            REQUIRE(dst.b == 0_nearly);
        }
        {
            constexpr RGB src{ 1.0, 1.0, 1.0 };
            const auto dst = ColorCast<DisplayP3>(src);

            REQUIRE(dst.r == 1_nearly);
            REQUIRE(dst.g == 1_nearly);
            REQUIRE(dst.b == 1_nearly);
        }
        {
            constexpr RGB src{ 0.1, 0.5, 0.9 };
            const auto dst = ColorCast<DisplayP3>(src);

            REQUIRE(dst.r == 0.046_nearly(0.01));
            REQUIRE(dst.g == 0.207_nearly(0.01));
            REQUIRE(dst.b == 0.732_nearly(0.01));
        }
    }
    SECTION("DisplayP3 Diff")
    {
        constexpr DisplayP3 a{ 1.0, 0.0, 1.0 };
        constexpr DisplayP3 b{ 0, 1.0, 0 };

        const double diff = ColorDiff::Euclidean<DisplayP3>(a, b);
        REQUIRE(diff == 1.7320504_nearly);
    }
}
