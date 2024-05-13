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

        friend constexpr bool operator==(const Luv_& a, const Luv_& b) = default;
    };

    using Luv50 = Luv_<struct D50>;
    using Luv65 = Luv_<struct D65>;
    using Luv = Luv65;
}
