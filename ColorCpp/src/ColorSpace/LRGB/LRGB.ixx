export module ColorCpp:LRGB;
import :Type;
import :Math;

export namespace colorcpp
{
    /// <summary>
    /// Linear RGB
    /// </summary>
    struct LRGB
    {
        /// <summary>
        /// Red [0, 1]
        /// </summary>
        double r;

        /// <summary>
        /// Green [0, 1]
        /// </summary>
        double g;

        /// <summary>
        /// Blue [0, 1]
        /// </summary>
        double b;

        [[nodiscard]] constexpr LRGB operator +(const LRGB& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr LRGB& operator +=(const LRGB& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        [[nodiscard]] constexpr LRGB operator -(const LRGB& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr LRGB& operator -=(const LRGB& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        [[nodiscard]] constexpr LRGB operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr LRGB& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }
        [[nodiscard]] constexpr LRGB operator *(const LRGB& other) const noexcept
        {
            return { r * other.r, g * other.g, b * other.b };
        }
        constexpr LRGB& operator *=(const LRGB& other) noexcept
        {
            r *= other.r;
            g *= other.g;
            b *= other.b;
            return *this;
        }
        [[nodiscard]] friend constexpr bool operator==(const LRGB& a, const LRGB& b) = default;
    };
}
