export module ColorCpp:HWB;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    /// <summary>
    /// HWB
    /// </summary>
    struct HWB
    {
        /// <summary>
        /// Hue 色相 [0, 360)
        /// </summary>
        double h;

        /// <summary>
        /// Whiteness [0, 1]
        /// </summary>
        double w;

        /// <summary>
        /// Blackness [0, 1]
        /// </summary>
        double b;

        [[nodiscard]] constexpr HWB operator +(const HWB& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h + other.h),
                Math::Saturate(w + other.w),
                Math::Saturate(b + other.b)
            };
        }
        constexpr HWB& operator +=(const HWB& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        [[nodiscard]] constexpr HWB operator -(const HWB& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h - other.h),
                Math::Saturate(w - other.w),
                Math::Saturate(b - other.b)
            };
        }
        constexpr HWB& operator -=(const HWB& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }

        [[nodiscard]] constexpr HWB operator *(double s) const noexcept
        {
            return{ InternalUtil::RepeatHue360(h * s), w * s, b * s };
        }
        constexpr HWB& operator *=(double s) noexcept
        {
            h = InternalUtil::RepeatHue360(h * s);
            w *= s;
            b *= s;
            return *this;
        }

        [[nodiscard]] friend constexpr bool operator==(const HWB& a, const HWB& b) = default;
    };
}
