export module ColorCpp:HSL;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    /// <summary>
    /// HSL (円柱モデル)
    /// </summary>
    template<class Model>
    struct HSL_
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
        /// Lightness 輝度 [0, 1]
        /// </summary>
        double l;

        [[nodiscard]] constexpr HSL_ operator +(const HSL_& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h + other.h),
                Math::Saturate(s + other.s),
                Math::Saturate(l + other.l)
            };
        }
        constexpr HSL_& operator +=(const HSL_& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        [[nodiscard]] constexpr HSL_ operator -(const HSL_& other) const noexcept
        {
            return{
                InternalUtil::RepeatHue360(h - other.h),
                Math::Saturate(s - other.s),
                Math::Saturate(l - other.l)
            };
        }
        constexpr HSL_& operator -=(const HSL_& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }
        [[nodiscard]] constexpr HSL_ operator *(double _s) const noexcept
        {
            return{ InternalUtil::RepeatHue360(h * _s), s * _s, l * _s };
        }
        constexpr HSL_& operator *=(double _s) noexcept
        {
            h = InternalUtil::RepeatHue360(h * _s);
            s *= _s;
            l *= _s;
            return *this;
        }
        [[nodiscard]] friend constexpr bool operator==(const HSL_& a, const HSL_& b) = default;
    };
    /// <summary>
    /// HSL (双円錐モデル)
    /// </summary>
    using HSLCone = HSL_<struct Cone>;

    /// <summary>
    /// HSV (円柱モデル)
    /// </summary>
    using HSLCylinder = HSL_<struct Cylinder>;

    using HSL = HSLCylinder;

    /// <summary>
    /// HSB
    /// </summary>
    using HSBCone = HSLCone;
    using HSBCylinder = HSLCylinder;
    using HSB = HSL;
}
