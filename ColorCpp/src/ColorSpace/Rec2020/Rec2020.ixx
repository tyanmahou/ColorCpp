export module ColorCpp:Rec2020;

export namespace colorcpp
{
    /// <summary>
    /// Rec.2020
    /// </summary>
    struct Rec2020
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

        [[nodiscard]] constexpr Rec2020 operator +(const Rec2020& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr Rec2020& operator +=(const Rec2020& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        [[nodiscard]] constexpr Rec2020 operator -(const Rec2020& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr Rec2020& operator -=(const Rec2020& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        [[nodiscard]] constexpr Rec2020 operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr Rec2020& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const Rec2020& a, const Rec2020& b) = default;
    };
}
