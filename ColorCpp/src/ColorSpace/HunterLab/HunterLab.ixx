export module ColorCpp:HunterLab;

export namespace colorcpp
{
    /// <summary>
    /// Hunter Lab色空間
    /// </summary>
    template<class Illuminant>
    struct HunterLab_
    {
        double l;
        double a;
        double b;

        constexpr HunterLab_ operator +(const HunterLab_& other) const noexcept
        {
            return { (l + other.l), (a + other.a), (b + other.b) };
        }
        constexpr HunterLab_& operator +=(const HunterLab_& other) noexcept
        {
            l += other.l;
            a += other.a;
            b += other.b;
            return *this;
        }
        constexpr HunterLab_ operator -(const HunterLab_& other) const noexcept
        {
            return{ (l - other.l), (a - other.a), (b - other.b) };
        }
        constexpr HunterLab_& operator -=(const HunterLab_& other) noexcept
        {
            l -= other.l;
            a -= other.a;
            b -= other.b;
            return *this;
        }

        friend constexpr bool operator==(const HunterLab_& a, const HunterLab_& b) = default;
    };

    using HunterLab50 = HunterLab_<struct D50>;
    using HunterLab65 = HunterLab_<struct D65>;
    using HunterLab = HunterLab65;
}
