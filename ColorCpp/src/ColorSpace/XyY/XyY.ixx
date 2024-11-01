export module ColorCpp:XyY;

export namespace colorcpp
{
    /// <summary>
    /// xyY色空間
    /// 0～1
    /// </summary>
    template<class Illuminant>
    struct XyY_
    {
        /// <summary>
        /// x [0, 1]
        /// </summary>
        double x;

        /// <summary>
        /// y [0, 1]
        /// </summary>
        double y1;

        /// <summary>
        /// Y [0, 1]
        /// </summary>
        double y2;

        [[nodiscard]] constexpr XyY_ operator +(const XyY_& other) const noexcept
        {
            return { (x + other.x), (y1 + other.y1), (y2 + other.y2) };
        }
        constexpr XyY_& operator +=(const XyY_& other) noexcept
        {
            x += other.x;
            y1 += other.y1;
            y2 += other.y2;
            return *this;
        }
        [[nodiscard]] constexpr XyY_ operator -(const XyY_& other) const noexcept
        {
            return{ (x - other.x), (y1 - other.y1), (y2 - other.y2) };
        }
        constexpr XyY_& operator -=(const XyY_& other) noexcept
        {
            x -= other.x;
            y1 -= other.y1;
            y2 -= other.y2;
            return *this;
        }
        [[nodiscard]] constexpr XyY_ operator *(double s) const noexcept
        {
            return{ x * s, y1 * s, y2 * s };
        }
        constexpr XyY_& operator *=(double s) noexcept
        {
            x *= s;
            y1 *= s;
            y2 *= s;
            return *this;
        }
        [[nodiscard]] constexpr XyY_ operator *(const XyY_& other) const noexcept
        {
            return{ x * other.x, y1 * other.y, y2 * other.y2 };
        }
        constexpr XyY_& operator *=(const XyY_& other) noexcept
        {
            x *= other.x;
            y1 *= other.y1;
            y2 *= other.y2;
            return *this;
        }
        [[nodiscard]] constexpr XyY_ operator /(double s) const noexcept
        {
            return{ x / s, y1 / s, y2 / s };
        }
        constexpr XyY_& operator /=(double s) noexcept
        {
            x /= s;
            y1 /= s;
            y2 /= s;
            return *this;
        }
        [[nodiscard]] constexpr XyY_ operator /(const XyY_& other) const noexcept
        {
            return{ x / other.x, y1 / other.y1, y2 / other.y2 };
        }
        constexpr XyY_& operator /=(const XyY_& other) noexcept
        {
            x /= other.x;
            y1 /= other.y1;
            y2 /= other.y2;
            return *this;
        }
        [[nodiscard]] friend constexpr bool operator==(const XyY_& a, const XyY_& b) = default;
    };

    using XyY50 = XyY_<struct D50>;
    using XyY65 = XyY_<struct D65>;
    using XyY = XyY65;
}
