﻿export module ColorCpp:Luv;

export namespace colorcpp
{
    /// <summary>
    /// Luv色空間
    /// </summary>
    struct Luv
    {
        double l;
        double u;
        double v;

        friend constexpr bool operator==(const Luv& a, const Luv& b) = default;
    };
}
