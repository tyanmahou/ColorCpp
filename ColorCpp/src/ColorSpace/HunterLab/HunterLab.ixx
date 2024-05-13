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

        friend constexpr bool operator==(const HunterLab_& a, const HunterLab_& b) = default;
    };

    using HunterLab50 = HunterLab_<struct D50>;
    using HunterLab65 = HunterLab_<struct D65>;
    using HunterLab = HunterLab65;
}
