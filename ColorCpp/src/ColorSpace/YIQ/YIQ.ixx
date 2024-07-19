export module ColorCpp:YIQ;

export namespace colorcpp
{
    struct YIQ
    {
        /// <summary>
        /// Y [0, 1]
        /// </summary>
        double y;

        /// <summary>
        /// I [0, 1]
        /// </summary>
        double i;

        /// <summary>
        /// Q [0, 1]
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
