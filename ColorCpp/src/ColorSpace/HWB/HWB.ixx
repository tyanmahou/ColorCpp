export module ColorCpp:HWB;
import :Math;
import :ColorUtil;

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

        constexpr HWB operator +(const HWB& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h + other.h),
                Math::Saturate(w + other.w),
                Math::Saturate(b + other.b)
            };
        }
        constexpr HWB& operator +=(const HWB& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        constexpr HWB operator -(const HWB& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h - other.h),
                Math::Saturate(w - other.w),
                Math::Saturate(b - other.b)
            };
        }
        constexpr HWB& operator -=(const HWB& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }
        friend constexpr bool operator==(const HWB& a, const HWB& b) = default;
    };
}
