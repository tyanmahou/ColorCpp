export module ColorCpp:LCH;

export namespace colorcpp
{
    /// <summary>
    /// LCH色空間
    /// </summary>
    template<class Illuminant>
    struct LCH_
    {
        /// <summary>
        /// 明度 [0, 100]
        /// </summary>
        double l;

        /// <summary>
        /// 彩度
        /// </summary>
        double c;

        /// <summary>
        /// 色相 [0, 360)
        /// </summary>
        double h;

        friend constexpr bool operator==(const LCH_& a, const LCH_& b) = default;
    };

    using LCH50 = LCH_<struct D50>;
    using LCH65 = LCH_<struct D65>;
    using LCH = LCH65;
}
