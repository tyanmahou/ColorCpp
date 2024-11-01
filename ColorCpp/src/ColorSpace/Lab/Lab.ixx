export module ColorCpp:Lab;

export namespace colorcpp
{
    /// <summary>
    /// Lab色空間
    /// </summary>
    template<class Illuminant>
    struct Lab_
    {
        double l;
        double a;
        double b;

        [[nodiscard]] constexpr Lab_ operator +(const Lab_& other) const noexcept
        {
            return { (l + other.l), (a + other.a), (b + other.b) };
        }
        constexpr Lab_& operator +=(const Lab_& other) noexcept
        {
            l += other.l;
            a += other.a;
            b += other.b;
            return *this;
        }
        [[nodiscard]] constexpr Lab_ operator -(const Lab_& other) const noexcept
        {
            return{ (l - other.l), (a - other.a), (b - other.b) };
        }
        constexpr Lab_& operator -=(const Lab_& other) noexcept
        {
            l -= other.l;
            a -= other.a;
            b -= other.b;
            return *this;
        }
        [[nodiscard]] constexpr Lab_ operator *(double s) const noexcept
        {
            return{ l * s, a * s, b * s };
        }
        constexpr Lab_& operator *=(double s) noexcept
        {
            l *= s;
            a *= s;
            b *= s;
            return *this;
        }
        [[nodiscard]] friend constexpr bool operator==(const Lab_& a, const Lab_& b) = default;
    };

    using Lab50 = Lab_<struct D50>;
    using Lab65 = Lab_<struct D65>;
    using Lab = Lab65;
}
