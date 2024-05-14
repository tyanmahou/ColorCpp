export module ColorCpp:HSL;
import :Math;
import :ColorUtil;

export namespace colorcpp
{
    /// <summary>
    /// HSL (円柱モデル)
    /// </summary>
    template<class Model>
    struct HSL_
    {
        /// <summary>
        /// 色相 [0, 360)
        /// </summary>
        double h;

        /// <summary>
        /// 彩度 [0, 1]
        /// </summary>
        double s;

        /// <summary>
        /// 輝度 [0, 1]
        /// </summary>
        double l;

        constexpr HSL_ operator +(const HSL_& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h + other.h),
                Math::Saturate(s + other.s),
                Math::Saturate(l + other.l)
            };
        }
        constexpr HSL_& operator +=(const HSL_& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        constexpr HSL_ operator -(const HSL_& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h - other.h),
                Math::Saturate(s - other.s),
                Math::Saturate(l - other.l)
            };
        }
        constexpr HSL_& operator -=(const HSL_& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }
        friend constexpr bool operator==(const HSL_& a, const HSL_& b) = default;
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
