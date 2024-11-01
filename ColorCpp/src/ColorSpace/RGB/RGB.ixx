export module ColorCpp:RGB;

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

        [[nodiscard]] constexpr RGB operator +(const RGB& other) const noexcept
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
        [[nodiscard]] constexpr RGB operator -(const RGB& other) const noexcept
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
        [[nodiscard]] constexpr RGB operator *(double s) const noexcept
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

        [[nodiscard]] friend constexpr bool operator==(const RGB& a, const RGB& b) = default;
    };
}
