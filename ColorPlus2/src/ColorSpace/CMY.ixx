﻿export module ColorPlus2:CMY;

export namespace cp2
{
	struct CMY
	{
		double c;
		double m;
		double y;

		constexpr CMY operator +(const CMY& other) const noexcept
		{
			return{ (c + other.c), (m + other.m), (y + other.y) };
		}
		constexpr CMY& operator +=(const CMY& other) noexcept
		{
			c += other.c;
			m += other.m;
			y += other.y;
			return *this;
		}
		constexpr CMY operator -(const CMY& other) const noexcept
		{
			return{ (c - other.c), (m - other.m), (y - other.y) };
		}
		constexpr CMY& operator -=(const CMY& other) noexcept
		{
			c -= other.c;
			m -= other.m;
			y -= other.y;
			return *this;
		}
		constexpr CMY operator *(double s) const noexcept
		{
			return{ c * s, m * s, y * s };
		}
		constexpr CMY& operator *=(double s) noexcept
		{
			c *= s;
			m *= s;
			y *= s;
			return *this;
		}

		friend constexpr bool operator==(const CMY& a, const CMY& b) = default;
	};

	struct CMYK
	{
		double c;
		double m;
		double y;
		double k;

		constexpr CMYK operator +(const CMYK& other) const noexcept
		{
			return{ (c + other.c), (m + other.m), (y + other.y), (k + other.k) };
		}
		constexpr CMYK& operator +=(const CMYK& other) noexcept
		{
			c += other.c;
			m += other.m;
			y += other.y;
			k += other.k;
			return *this;
		}
		constexpr CMYK operator -(const CMYK& other) const noexcept
		{
			return{ (c - other.c), (m - other.m), (y - other.y), (k - other.k) };
		}
		constexpr CMYK& operator -=(const CMYK& other) noexcept
		{
			c -= other.c;
			m -= other.m;
			y -= other.y;
			k -= other.k;
			return *this;
		}
		constexpr CMYK operator *(double s) const noexcept
		{
			return{ c * s, m * s, y * s, k * s };
		}
		constexpr CMYK& operator *=(double s) noexcept
		{
			c *= s;
			m *= s;
			y *= s;
			k *= s;
			return *this;
		}

		friend constexpr bool operator==(const CMYK& a, const CMYK& b) = default;
	};
}