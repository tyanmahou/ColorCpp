export module ColorCpp:CMY;

export namespace colorcpp
{
    struct CMY
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

        [[nodiscard]] constexpr CMY operator +(const CMY& other) const noexcept
        {
            return{ (c + other.c), (m + other.m), (y + other.y) };
        }
        constexpr CMY& operator +=(const CMY& other) noexcept
        {
            c += other.c;
            m += other.m;
            y += other.y;
            return *this;
        }
        [[nodiscard]] constexpr CMY operator -(const CMY& other) const noexcept
        {
            return{ (c - other.c), (m - other.m), (y - other.y) };
        }
        constexpr CMY& operator -=(const CMY& other) noexcept
        {
            c -= other.c;
            m -= other.m;
            y -= other.y;
            return *this;
        }
        [[nodiscard]] constexpr CMY operator *(double s) const noexcept
        {
            return{ c * s, m * s, y * s };
        }
        constexpr CMY& operator *=(double s) noexcept
        {
            c *= s;
            m *= s;
            y *= s;
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const CMY& a, const CMY& b) = default;
    };
}
