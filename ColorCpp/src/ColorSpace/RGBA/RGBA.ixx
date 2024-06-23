export module ColorCpp:RGBA;

export namespace colorcpp
{
    /// <summary>
    /// sRGB Alpha
    /// </summary>
    struct RGBA
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

        /// <summary>
        /// Alpha [0, 1]
        /// </summary>
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
}
