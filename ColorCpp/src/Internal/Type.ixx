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
}
