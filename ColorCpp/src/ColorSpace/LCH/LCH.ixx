export module ColorCpp:LCH;
import :InternalUtil;

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

        [[nodiscard]] constexpr LCH_ operator +(const LCH_& other) const noexcept
        {
            return { (l + other.l), (c + other.c), InternalUtil::RepeatHue360(h + other.h) };
        }
        constexpr LCH_& operator +=(const LCH_& other) noexcept
        {
            l += other.l;
            c += other.c;
            h = InternalUtil::RepeatHue360(h + other.h);
            return *this;
        }
        [[nodiscard]] constexpr LCH_ operator -(const LCH_& other) const noexcept
        {
            return{ (l - other.l), (c - other.c), InternalUtil::RepeatHue360(h - other.h) };
        }
        constexpr LCH_& operator -=(const LCH_& other) noexcept
        {
            l -= other.l;
            c -= other.c;
            h = InternalUtil::RepeatHue360(h - other.h);
            return *this;
        }
        [[nodiscard]] constexpr LCH_ operator *(double s) const noexcept
        {
            return{ l * s, c * s, InternalUtil::RepeatHue360(h * s) };
        }
        constexpr LCH_& operator *=(double s) noexcept
        {
            l *= s;
            c *= s;
            h = InternalUtil::RepeatHue360(h * s);
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const LCH_& a, const LCH_& b) = default;
    };

    using LCH50 = LCH_<struct D50>;
    using LCH65 = LCH_<struct D65>;
    using LCH = LCH65;
}
