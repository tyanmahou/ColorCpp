export module ColorCpp:Luv;

export namespace colorcpp
{
    /// <summary>
    /// Luv色空間
    /// </summary>
    template<class Illuminant>
    struct Luv_
    {
        double l;
        double u;
        double v;

        constexpr Luv_ operator +(const Luv_& other) const noexcept
        {
            return { (l + other.l), (u + other.u), (v + other.v) };
        }
        constexpr Luv_& operator +=(const Luv_& other) noexcept
        {
            l += other.l;
            u += other.u;
            v += other.v;
            return *this;
        }
        constexpr Luv_ operator -(const Luv_& other) const noexcept
        {
            return{ (l - other.l), (u - other.u), (v - other.v) };
        }
        constexpr Luv_& operator -=(const Luv_& other) noexcept
        {
            l -= other.l;
            u -= other.u;
            v -= other.v;
            return *this;
        }

        friend constexpr bool operator==(const Luv_& a, const Luv_& b) = default;
    };

    using Luv50 = Luv_<struct D50>;
    using Luv65 = Luv_<struct D65>;
    using Luv = Luv65;
}
