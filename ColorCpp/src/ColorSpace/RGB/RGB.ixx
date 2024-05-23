export module ColorCpp:RGB;
import :Type;
import :Math;

export namespace colorcpp
{
    /// <summary>
    /// sRGB
    /// </summary>
    struct RGB
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

        constexpr RGB operator +(const RGB& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr RGB& operator +=(const RGB& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        constexpr RGB operator -(const RGB& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr RGB& operator -=(const RGB& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        constexpr RGB operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr RGB& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }

        friend constexpr bool operator==(const RGB& a, const RGB& b) = default;
    };
}
