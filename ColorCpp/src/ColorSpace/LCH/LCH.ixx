export module ColorCpp:LCH;

export namespace colorcpp
{
    /// <summary>
    /// LCH色空間
    /// </summary>
    struct LCH
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

        friend constexpr bool operator==(const LCH& a, const LCH& b) = default;
    };
}
