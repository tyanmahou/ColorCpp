module;
#include <cstdint>

export module ColorPlus2:Type;

namespace cp2
{
    using uint8 = std::uint8_t;

    constexpr inline uint8 DoubleToUInt8(double v)
    {
        if (v >= 1.0) {
            return 255;
        }
        if (v <= 0.0) {
            return 0;
        }
        return static_cast<uint8>(v * 255.0 + 0.5);
    }
    constexpr inline double UInt8ToDouble(uint8 v)
    {
        return v / 255.0;
    }
}