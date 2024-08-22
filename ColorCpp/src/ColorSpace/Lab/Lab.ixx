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

        constexpr Lab_ operator +(const Lab_& other) const noexcept
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
        constexpr Lab_ operator -(const Lab_& other) const noexcept
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

        friend constexpr bool operator==(const Lab_& a, const Lab_& b) = default;
    };

    using Lab50 = Lab_<struct D50>;
    using Lab65 = Lab_<struct D65>;
    using Lab = Lab65;
}
