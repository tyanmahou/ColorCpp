export module ColorCpp:XYZ;

export namespace colorcpp
{
    /// <summary>
    /// XYZ色空間
    /// 0～1
    /// </summary>
    template<class Illuminant>
    struct XYZ_
    {
        /// <summary>
        /// X [0, 1]
        /// </summary>
        double x;

        /// <summary>
        /// Y [0, 1]
        /// </summary>
        double y;

        /// <summary>
        /// Z [0, 1]
        /// </summary>
        double z;

        constexpr XYZ_ operator +(const XYZ_& other) const noexcept
        {
            return { (x + other.x), (y + other.y), (z + other.z) };
        }
        constexpr XYZ_& operator +=(const XYZ_& other) noexcept
        {
            x += other.x;
            y += other.y;
            z += other.z;
            return *this;
        }
        constexpr XYZ_ operator -(const XYZ_& other) const noexcept
        {
            return{ (x - other.x), (y - other.y), (z - other.z) };
        }
        constexpr XYZ_& operator -=(const XYZ_& other) noexcept
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            return *this;
        }
        constexpr XYZ_ operator *(double s) const noexcept
        {
            return{ x * s, y * s, z * s };
        }
        constexpr XYZ_& operator *=(double s) noexcept
        {
            x *= s;
            y *= s;
            z *= s;
            return *this;
        }
        constexpr XYZ_ operator *(const XYZ_& other) const noexcept
        {
            return{ x * other.x, y * other.y, z * other.z };
        }
        constexpr XYZ_& operator *=(const XYZ_& other) noexcept
        {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            return *this;
        }
        constexpr XYZ_ operator /(double s) const noexcept
        {
            return{ x / s, y / s, z / s };
        }
        constexpr XYZ_& operator /=(double s) noexcept
        {
            x /= s;
            y /= s;
            z /= s;
            return *this;
        }
        constexpr XYZ_ operator /(const XYZ_& other) const noexcept
        {
            return{ x / other.x, y / other.y, z / other.z };
        }
        constexpr XYZ_& operator /=(const XYZ_& other) noexcept
        {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            return *this;
        }
        friend constexpr bool operator==(const XYZ_& a, const XYZ_& b) = default;
    };

    using XYZ50 = XYZ_<struct D50>;
    using XYZ65 = XYZ_<struct D65>;
    using XYZ = XYZ65;

    template<class Illuminant>
    inline constexpr XYZ_<Illuminant> WhitePoint{ 1, 1, 1 };

    template<>
    inline constexpr XYZ50 WhitePoint<D50>{ 0.96419503, 1.0, 0.82511874};

    template<>
    inline constexpr XYZ65 WhitePoint<D65>{ 0.950456, 1.0, 1.088754 };
}
