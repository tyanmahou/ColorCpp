export module ColorCpp:OkLCH;

export namespace colorcpp
{
    /// <summary>
    /// Ok LCH色空間
    /// </summary>
    struct OkLCH
    {
        /// <summary>
        /// 明度 [0, 1]
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

        friend constexpr bool operator==(const OkLCH& a, const OkLCH& b) = default;
    };
}
