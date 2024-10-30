export module ColorCpp:OkLab;

export namespace colorcpp
{
    /// <summary>
    /// Ok Lab色空間
    /// </summary>
    struct OkLab
    {
        double l;
        double a;
        double b;

        constexpr OkLab operator +(const OkLab& other) const noexcept
        {
            return { (l + other.l), (a + other.a), (b + other.b) };
        }
        constexpr OkLab& operator +=(const OkLab& other) noexcept
        {
            l += other.l;
            a += other.a;
            b += other.b;
            return *this;
        }
        constexpr OkLab operator -(const OkLab& other) const noexcept
        {
            return{ (l - other.l), (a - other.a), (b - other.b) };
        }
        constexpr OkLab& operator -=(const OkLab& other) noexcept
        {
            l -= other.l;
            a -= other.a;
            b -= other.b;
            return *this;
        }

        friend constexpr bool operator==(const OkLab& a, const OkLab& b) = default;
    };
}
