export module ColorCpp:A98;

export namespace colorcpp
{
    /// <summary>
    /// Adobe RGB 1998
    /// </summary>
    struct A98
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

        [[nodiscard]] constexpr A98 operator +(const A98& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr A98& operator +=(const A98& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        [[nodiscard]] constexpr A98 operator -(const A98& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr A98& operator -=(const A98& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        [[nodiscard]] constexpr A98 operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr A98& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const A98& a, const A98& b) = default;
    };
}
