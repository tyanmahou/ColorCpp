export module ColorPlus2:RGB;
import :Type;
import :Math;

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

	struct RGBA
	{
		double r;
		double g;
		double b;
		double a;

		constexpr RGBA operator +(const RGBA& other) const noexcept
		{
			return{ (r + other.r), (g + other.g), (b + other.b) , (a + other.a) };
		}
		constexpr RGBA& operator +=(const RGBA& other) noexcept
		{
			r += other.r;
			g += other.g;
			b += other.b;
			a += other.a;
			return *this;
		}
		constexpr RGBA operator -(const RGBA& other) const noexcept
		{
			return{ (r - other.r), (g - other.g), (b - other.b), (a - other.a) };
		}
		constexpr RGBA& operator -=(const RGBA& other) noexcept
		{
			r -= other.r;
			g -= other.g;
			b -= other.b;
			a -= other.a;
			return *this;
		}
		constexpr RGBA operator *(double s) const noexcept
		{
			return { r * s, g * s, b * s, a * s };
		}
		constexpr RGBA& operator *=(double s) noexcept
		{
			r *= s;
			g *= s;
			b *= s;
			a *= s;
			return *this;
		}

		friend constexpr bool operator==(const RGBA& a, const RGBA& b) = default;
	};

	struct RGBA32
	{
		using value_type = uint8;

		value_type r;
		value_type g;
		value_type b;
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

	constexpr inline double LinearToSRGB(double v)
	{
		if (v <= 0.0031308) {
			return 12.92 * v;
		} else {
			return 1.055 * Pow(v, 1.0 / 2.4) - 0.055;
		}
	}
	constexpr inline RGB LinearToSRGB(const RGB& rgb)
	{
		return {
			.r = LinearToSRGB(rgb.r),
			.g = LinearToSRGB(rgb.g),
			.b = LinearToSRGB(rgb.b),
		};
	}
	constexpr inline double SRGBToLinear(double v)
	{
		if (v <= 0.04045) {
			return v / 12.92;
		} else {
			return Pow((v + 0.055) / 1.055, 2.4);
		}
	}
	constexpr inline RGB SRGBToLinear(const RGB& rgb)
	{
		return {
			.r = SRGBToLinear(rgb.r),
			.g = SRGBToLinear(rgb.g),
			.b = SRGBToLinear(rgb.b),
		};
	}
	constexpr inline double LinearToAdobeRGB(double v)
	{
		return Pow(v, 1.0 / 2.19921875);
	}
	constexpr inline RGB LinearToAdobeRGB(const RGB& rgb)
	{
		return {
			.r = LinearToAdobeRGB(rgb.r),
			.g = LinearToAdobeRGB(rgb.g),
			.b = LinearToAdobeRGB(rgb.b),
		};
	}
	constexpr inline double AdobeRGBToLinear(double v)
	{
		return Pow(v, 2.19921875);
	}
	constexpr inline RGB AdobeRGBToLinear(const RGB& rgb)
	{
		return {
			.r = AdobeRGBToLinear(rgb.r),
			.g = AdobeRGBToLinear(rgb.g),
			.b = AdobeRGBToLinear(rgb.b),
		};
	}
}