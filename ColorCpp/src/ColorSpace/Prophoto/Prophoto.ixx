export module ColorCpp:Prophoto;

export namespace colorcpp
{
    /// <summary>
    /// Prophoto RGB
    /// </summary>
    struct Prophoto
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

        constexpr Prophoto operator +(const Prophoto& other) const noexcept
        {
            return{ (r + other.r), (g + other.g), (b + other.b) };
        }
        constexpr Prophoto& operator +=(const Prophoto& other) noexcept
        {
            r += other.r;
            g += other.g;
            b += other.b;
            return *this;
        }
        constexpr Prophoto operator -(const Prophoto& other) const noexcept
        {
            return{ (r - other.r), (g - other.g), (b - other.b) };
        }
        constexpr Prophoto& operator -=(const Prophoto& other) noexcept
        {
            r -= other.r;
            g -= other.g;
            b -= other.b;
            return *this;
        }
        constexpr Prophoto operator *(double s) const noexcept
        {
            return{ r * s, g * s, b * s };
        }
        constexpr Prophoto& operator *=(double s) noexcept
        {
            r *= s;
            g *= s;
            b *= s;
            return *this;
        }

        friend constexpr bool operator==(const Prophoto& a, const Prophoto& b) = default;
    };
}
