import ColorCpp;

#include "catch.hpp"
#include "TestUtil.hpp"
using namespace colorcpp;

TEST_CASE("HWB")
{
    SECTION("RGB to HWB")
    {
        {
            constexpr RGB rgb{ 0, 0, 0 };
            HWB hwb = ColorCast<HWB>(rgb);
            REQUIRE(hwb.h == 0_nearly);
            REQUIRE(hwb.w == 0_nearly);
            REQUIRE(hwb.b == 1_nearly);
        }
        {
            constexpr RGB rgb{ 1, 1, 1 };
            HWB hwb = ColorCast<HWB>(rgb);
            REQUIRE(hwb.h == 0_nearly);
            REQUIRE(hwb.w == 1_nearly);
            REQUIRE(hwb.b == 0_nearly);
        }
        {
            constexpr RGB rgb{ 1, 0, 0 };
            HWB hwb = ColorCast<HWB>(rgb);
            REQUIRE(hwb.h == 0_nearly);
            REQUIRE(hwb.w == 0_nearly);
            REQUIRE(hwb.b == 0_nearly);
        }
        {
            constexpr RGB rgb{ 0.5, 0.5, 0.5 };
            HWB hwb = ColorCast<HWB>(rgb);
            REQUIRE(hwb.h == 0_nearly);
            REQUIRE(hwb.w == 0.5_nearly);
            REQUIRE(hwb.b == 0.5_nearly);
        }
    }
    SECTION("HWB to RGB")
    {
        {
            constexpr HWB hwb{ 0, 0, 1 };
            RGB rgb = ColorCast<RGB>(hwb);
            REQUIRE(rgb.r == 0.0_nearly);
            REQUIRE(rgb.g == 0.0_nearly);
            REQUIRE(rgb.b == 0.0_nearly);
        }
        {
            constexpr HWB hwb{ 0, 1, 0 };
            RGB rgb = ColorCast<RGB>(hwb);
            REQUIRE(rgb.r == 1.0_nearly);
            REQUIRE(rgb.g == 1.0_nearly);
            REQUIRE(rgb.b == 1.0_nearly);
        }
        {
            constexpr HWB hwb{ 0, 0, 0 };
            RGB rgb = ColorCast<RGB>(hwb);
            REQUIRE(rgb.r == 1.0_nearly);
            REQUIRE(rgb.g == 0.0_nearly);
            REQUIRE(rgb.b == 0.0_nearly);
        }
        {
            constexpr HWB hwb{ 0, 0.5, 0.5 };
            RGB rgb = ColorCast<RGB>(hwb);
            REQUIRE(rgb.r == 0.5_nearly);
            REQUIRE(rgb.g == 0.5_nearly);
            REQUIRE(rgb.b == 0.5_nearly);
        }
    }
}
