export module ColorCpp:YIQ;

export namespace colorcpp
{
    /// <summary>
    /// YIQ色空間
    /// </summary>
    struct YIQ
    {
        /// <summary>
        /// Y
        /// </summary>
        double y;

        /// <summary>
        /// I
        /// </summary>
        double i;

        /// <summary>
        /// Q
        /// </summary>
        double q;

        constexpr YIQ operator +(const YIQ& other) const noexcept
        {
            return { (y + other.y), (i + other.i), (q + other.q) };
        }
        constexpr YIQ& operator +=(const YIQ& other) noexcept
        {
            y += other.y;
            i += other.i;
            q += other.q;
            return *this;
        }
        constexpr YIQ operator -(const YIQ& other) const noexcept
        {
            return{ (y - other.y), (i - other.i), (q - other.q) };
        }
        constexpr YIQ& operator -=(const YIQ& other) noexcept
        {
            y -= other.y;
            i -= other.i;
            q -= other.q;
            return *this;
        }
        constexpr YIQ operator *(double s) const noexcept
        {
            return{ y * s, i * s, q * s };
        }
        constexpr YIQ& operator *=(double s) noexcept
        {
            y *= s;
            i *= s;
            q *= s;
            return *this;
        }
        constexpr YIQ operator *(const YIQ& other) const noexcept
        {
            return{ y * other.y, i * other.i, q * other.q };
        }
        constexpr YIQ& operator *=(const YIQ& other) noexcept
        {
            y *= other.y;
            i *= other.i;
            q *= other.q;
            return *this;
        }
        constexpr YIQ operator /(double s) const noexcept
        {
            return{ y / s, i / s, q / s };
        }
        constexpr YIQ& operator /=(double s) noexcept
        {
            y /= s;
            i /= s;
            q /= s;
            return *this;
        }
        constexpr YIQ operator /(const YIQ& other) const noexcept
        {
            return{ y / other.y, i / other.i, q / other.q };
        }
        constexpr YIQ& operator /=(const YIQ& other) noexcept
        {
            y /= other.y;
            i /= other.i;
            q /= other.q;
            return *this;
        }

        friend constexpr bool operator==(const YIQ& a, const YIQ& b) = default;
    };
}
