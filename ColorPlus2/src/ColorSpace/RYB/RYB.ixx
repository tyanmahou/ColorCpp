export module ColorPlus2:RYB;

export namespace cp2
{
    struct RYB
    {
        /// <summary>
        /// Red [0, 1]
        /// </summary>
        double r;

        /// <summary>
        /// Yellow [0, 1]
        /// </summary>
        double y;

        /// <summary>
        /// Blue [0, 1]
        /// </summary>
        double b;

		constexpr RYB operator +(const RYB& other) const noexcept
		{
			return{ (r + other.r), (y + other.y), (b + other.b) };
		}
		constexpr RYB& operator +=(const RYB& other) noexcept
		{
			r += other.r;
			y += other.y;
			b += other.b;
			return *this;
		}
		constexpr RYB operator -(const RYB& other) const noexcept
		{
			return{ (r - other.r), (y - other.y), (b - other.b) };
		}
		constexpr RYB& operator -=(const RYB& other) noexcept
		{
			r -= other.r;
			y -= other.y;
			b -= other.b;
			return *this;
		}
		constexpr RYB operator *(double s) const noexcept
		{
			return{ r * s, y * s, b * s };
		}
		constexpr RYB& operator *=(double s) noexcept
		{
			r *= s;
			y *= s;
			b *= s;
			return *this;
		}

		friend constexpr bool operator==(const RYB& a, const RYB& b) = default;
    };
}