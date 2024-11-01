export module ColorCpp:CastXyY;
import :ColorCastTrait;

import :XYZ;
import :XyY;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<XyY_<Illuminant>>
    {
        using depend_type = XYZ_<Illuminant>;
    };

    // xyY <=> XYZ
    template<class Illuminant>
    struct ColorCastTraits<XyY_<Illuminant>, XYZ_<Illuminant>>
    {
        [[nodiscard]] constexpr static XyY_<Illuminant> Cast(const XYZ_<Illuminant>& xyz)
        {
            const auto& [x, y, z] = xyz;
            const double sum = x + y + z;

            return {
                .x = (sum == 0) ? 0 : x / sum,
                .y1 = (sum == 0) ? 0 : y / sum,
                .y2 = y
            };
        }
    };
    template<class Illuminant>
    struct ColorCastTraits<XYZ_<Illuminant>, XyY_<Illuminant>>
    {
        [[nodiscard]] constexpr static XYZ_<Illuminant> Cast(const XyY_<Illuminant>& xyY)
        {
            const auto& [x, y, Y] = xyY;

            return {
                .x = (y == 0) ? 0 : x * Y / y,
                .y = Y,
                .z = (y == 0) ? 0 : (1 - x - y)  * Y / y,
            };
        }
    };
}
