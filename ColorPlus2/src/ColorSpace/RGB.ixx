export module ColorPlus2:RGB;

export namespace cp2
{
    struct RGB
    {
        double r;
        double g;
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