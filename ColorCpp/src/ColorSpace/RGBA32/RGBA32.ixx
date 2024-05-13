export module ColorCpp:RGBA32;
import :Type;
import :Math;

export namespace colorcpp
{
	/// <summary>
	/// sRGB Alpha
	/// </summary>
	struct RGBA32
	{
		using value_type = uint8;

		/// <summary>
		/// Red [0, 255]
		/// </summary>
		value_type r;

		/// <summary>
		/// Green [0, 255]
		/// </summary>
		value_type g;

		/// <summary>
		/// Blue [0, 255]
		/// </summary>
		value_type b;

		/// <summary>
		/// Alpha [0, 255]
		/// </summary>
		value_type a;

		constexpr RGBA32 operator +(const RGBA32& other) const noexcept
		{
			return {
				static_cast<value_type>(r + other.r),
				static_cast<value_type>(g + other.g),
				static_cast<value_type>(b + other.b),
				static_cast<value_type>(a + other.a),
			};
		}
		constexpr RGBA32& operator +=(const RGBA32& other) noexcept
		{
			r += other.r;
			g += other.g;
			b += other.b;
			a += other.a;
			return *this;
		}
		constexpr RGBA32 operator -(const RGBA32& other) const noexcept
		{
			return{
				static_cast<value_type>(r - other.r),
				static_cast<value_type>(g - other.g),
				static_cast<value_type>(b - other.b),
				static_cast<value_type>(a - other.a)
			};
		}
		constexpr RGBA32& operator -=(const RGBA32& other) noexcept
		{
			r -= other.r;
			g -= other.g;
			b -= other.b;
			a -= other.a;
			return *this;
		}
		constexpr RGBA32 operator *(value_type s) const noexcept
		{
			return{
				static_cast<value_type>(r * s),
				static_cast<value_type>(g * s),
				static_cast<value_type>(b * s),
				static_cast<value_type>(a * s)
			};
		}
		constexpr RGBA32& operator *=(value_type s) noexcept
		{
			r *= s;
			g *= s;
			b *= s;
			a *= s;
			return *this;
		}

		friend constexpr bool operator==(const RGBA32& a, const RGBA32& b) = default;
	};
}