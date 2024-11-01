export module ColorCpp:DisplayP3;

export namespace colorcpp
{
    /// <summary>
    /// DisplayP3
    /// </summary>
    struct DisplayP3
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

        [[nodiscard]] constexpr DisplayP3 operator +(const DisplayP3& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr DisplayP3& operator +=(const DisplayP3& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        [[nodiscard]] constexpr DisplayP3 operator -(const DisplayP3& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr DisplayP3& operator -=(const DisplayP3& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        [[nodiscard]] constexpr DisplayP3 operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr DisplayP3& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const DisplayP3& a, const DisplayP3& b) = default;
    };
}
