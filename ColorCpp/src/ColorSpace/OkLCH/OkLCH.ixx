export module ColorCpp:OkLCH;
import :InternalUtil;

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

        [[nodiscard]] constexpr OkLCH operator +(const OkLCH& other) const noexcept
        {
            return { (l + other.l), (c + other.c), InternalUtil::RepeatHue360(h + other.h) };
        }
        constexpr OkLCH& operator +=(const OkLCH& other) noexcept
        {
            l += other.l;
            c += other.c;
            h = InternalUtil::RepeatHue360(h + other.h);
            return *this;
        }
        [[nodiscard]] constexpr OkLCH operator -(const OkLCH& other) const noexcept
        {
            return{ (l - other.l), (c - other.c), InternalUtil::RepeatHue360(h - other.h) };
        }
        constexpr OkLCH& operator -=(const OkLCH& other) noexcept
        {
            l -= other.l;
            c -= other.c;
            h = InternalUtil::RepeatHue360(h - other.h);
            return *this;
        }
        [[nodiscard]] constexpr OkLCH operator *(double s) const noexcept
        {
            return{ l * s, c * s, InternalUtil::RepeatHue360(h * s) };
        }
        constexpr OkLCH& operator *=(double s) noexcept
        {
            l *= s;
            c *= s;
            h = InternalUtil::RepeatHue360(h * s);
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const OkLCH& a, const OkLCH& b) = default;
    };
}
