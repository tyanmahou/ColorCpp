export module ColorPlus2:CMYK;

export namespace colorp2
{
    struct CMYK
    {
        /// <summary>
        /// Cyan [0, 1]
        /// </summary>
        double c;

        /// <summary>
        /// Magenta [0, 1]
        /// </summary>
        double m;

        /// <summary>
        /// Yellow [0, 1]
        /// </summary>
        double y;

        /// <summary>
        /// Black [0, 1]
        /// </summary>
        double k;

        constexpr CMYK operator +(const CMYK& other) const noexcept
        {
            return{ (c + other.c), (m + other.m), (y + other.y), (k + other.k) };
        }
        constexpr CMYK& operator +=(const CMYK& other) noexcept
        {
            c += other.c;
            m += other.m;
            y += other.y;
            k += other.k;
            return *this;
        }
        constexpr CMYK operator -(const CMYK& other) const noexcept
        {
            return{ (c - other.c), (m - other.m), (y - other.y), (k - other.k) };
        }
        constexpr CMYK& operator -=(const CMYK& other) noexcept
        {
            c -= other.c;
            m -= other.m;
            y -= other.y;
            k -= other.k;
            return *this;
        }
        constexpr CMYK operator *(double s) const noexcept
        {
            return{ c * s, m * s, y * s, k * s };
        }
        constexpr CMYK& operator *=(double s) noexcept
        {
            c *= s;
            m *= s;
            y *= s;
            k *= s;
            return *this;
        }

        friend constexpr bool operator==(const CMYK& a, const CMYK& b) = default;
    };
}