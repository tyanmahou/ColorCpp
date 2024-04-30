export module ColorPlus2:XYZ;

export namespace cp2
{
	struct XYZ
	{
		double x;
		double y;
		double z;

		constexpr XYZ operator +(const XYZ& other) const noexcept
		{
			return{ (x + other.x), (y + other.y), (z + other.z) };
		}
		constexpr XYZ& operator +=(const XYZ& other) noexcept
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}
		constexpr XYZ operator -(const XYZ& other) const noexcept
		{
			return{ (x - other.x), (y - other.y), (z - other.z) };
		}
		constexpr XYZ& operator -=(const XYZ& other) noexcept
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}
		constexpr XYZ operator *(double s) const noexcept
		{
			return{ x * s, y * s, z * s };
		}
		constexpr XYZ& operator *=(double s) noexcept
		{
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}

		friend constexpr bool operator==(const XYZ& a, const XYZ& b) = default;
	};
}