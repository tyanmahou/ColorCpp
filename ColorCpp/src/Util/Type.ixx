module;
#include <cstdint>

export module ColorCpp:Type;
import <concepts>;

namespace colorcpp
{
    using int32 = std::int32_t;
    using uint8 = std::uint8_t;
    using uint32 = std::uint32_t;

    template <typename T>
    concept Character =
        std::same_as<T, char> ||
        std::same_as<T, signed char> ||
        std::same_as<T, unsigned char> ||
        std::same_as<T, wchar_t> ||
        std::same_as<T, char8_t> ||
        std::same_as<T, char16_t> ||
        std::same_as<T, char32_t>;

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

    constexpr inline uint8 HexToDecimal(char hex)
    {
        // 1,A,aの下位4bitがそれぞれ 0x01～なので0x0Fでマスクすると
        // 0～9 => 0～9, A～F => 1～6, a～f => 1～6になる
        // (hex & 0x40) >> 6 で 0～9 => 0, a～f,A～F => 1　になる
        return (hex & 0x0F) + ((hex & 0x40) >> 6) * 9;
    }
    constexpr inline char DecimalToHex(uint8 d)
    {
        return d >= 10 ? (d - 10) + 'A' : d + '0';
    }
}
