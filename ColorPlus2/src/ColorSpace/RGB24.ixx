﻿export module ColorPlus2:RGB24;
import :Type;

export namespace cp2
{
	struct RGB24
	{
		using value_type = uint8;

		value_type r;
		value_type g;
		value_type b;

		constexpr RGB24 operator +(const RGB24& other) const noexcept
		{
			return { 
				static_cast<value_type>(r + other.r),
				static_cast<value_type>(g + other.g),
				static_cast<value_type>(b + other.b)
			};
		}
		constexpr RGB24& operator +=(const RGB24& other) noexcept
		{
			r += other.r;
			g += other.g;
			b += other.b;
			return *this;
		}
		constexpr RGB24 operator -(const RGB24& other) const noexcept
		{
			return{ 
				static_cast<value_type>(r - other.r),
				static_cast<value_type>(g - other.g),
				static_cast<value_type>(b - other.b)
			};
		}
		constexpr RGB24& operator -=(const RGB24& other) noexcept
		{
			r -= other.r;
			g -= other.g;
			b -= other.b;
			return *this;
		}
		constexpr RGB24 operator *(value_type s) const noexcept
		{
			return{ 
				static_cast<value_type>(r * s),
				static_cast<value_type>(g * s), 
				static_cast<value_type>(b * s)
			};
		}
		constexpr RGB24& operator *=(value_type s) noexcept
		{
			r *= s;
			g *= s;
			b *= s;
			return *this;
		}

		friend constexpr bool operator==(const RGB24& a, const RGB24& b) = default;
	};
}