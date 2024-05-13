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

	constexpr inline double LinearToSRGB(double v)
	{
		if (v <= 0.0031308) {
			return 12.92 * v;
		} else {
			return 1.055 * Math::Pow(v, 1.0 / 2.4) - 0.055;
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
			return Math::Pow((v + 0.055) / 1.055, 2.4);
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
		return Math::Pow(v, 1.0 / 2.19921875);
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
		return Math::Pow(v, 2.19921875);
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