export module ColorCpp:HSI;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    /// <summary>
    /// HSI
    /// </summary>
    struct HSI
    {
        /// <summary>
        /// Hue 色相 [0, 360)
        /// </summary>
        double h;

        /// <summary>
        /// Saturation 彩度 [0, 1]
        /// </summary>
        double s;

        /// <summary>
        /// Intensity 強度 [0, 1]
        /// </summary>
        double i;

        [[nodiscard]] constexpr HSI operator +(const HSI& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h + other.h),
                Math::Saturate(s + other.s),
                Math::Saturate(i + other.i)
            };
        }
        constexpr HSI& operator +=(const HSI& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        [[nodiscard]] constexpr HSI operator -(const HSI& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h - other.h),
                Math::Saturate(s - other.s),
                Math::Saturate(i - other.i)
            };
        }
        constexpr HSI& operator -=(const HSI& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }
        [[nodiscard]] constexpr HSI operator *(double _s) const noexcept
        {
            return{ InternalUtil::RepeatHue360(h * _s), s * _s, i * _s };
        }
        constexpr HSI& operator *=(double _s) noexcept
        {
            h = InternalUtil::RepeatHue360(h * _s);
            s *= _s;
            i *= _s;
            return *this;
        }
        [[nodiscard]] friend constexpr bool operator==(const HSI& a, const HSI& b) = default;
    };
}
