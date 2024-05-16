export module ColorCpp:ITP;

export namespace colorcpp
{
    /// <summary>
    /// ITP(ICtCp)色空間
    /// </summary>
    struct ITP
    {
        double i;
        double t;
        double p;

        friend constexpr bool operator==(const ITP& a, const ITP& b) = default;
    };
}
