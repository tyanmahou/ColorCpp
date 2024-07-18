export module ColorCpp:YIQ;

export namespace colorcpp
{
    struct YIQ
    {
        /// <summary>
        /// Y [0, 1]
        /// </summary>
        double y;

        /// <summary>
        /// I [0, 1]
        /// </summary>
        double i;

        /// <summary>
        /// Q [0, 1]
        /// </summary>
        double q;

        friend constexpr bool operator==(const YIQ& a, const YIQ& b) = default;
    };
}
