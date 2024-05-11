export module ColorPlus2:LRGB;
import :Type;
import :Math;

export namespace cp2
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

		constexpr LRGB operator +(const LRGB& other) const noexcept
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
		constexpr LRGB operator -(const LRGB& other) const noexcept
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
		constexpr LRGB operator *(double s) const noexcept
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

		friend constexpr bool operator==(const LRGB& a, const LRGB& b) = default;
    };
}