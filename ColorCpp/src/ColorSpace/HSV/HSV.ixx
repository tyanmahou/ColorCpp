export module ColorCpp:HSV;
import :Math;
import :ColorUtil;

export namespace colorcpp
{
    /// <summary>
    /// HSV
    /// </summary>
    template<class Model>
    struct HSV_
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
        /// 明度 [0, 1]
        /// </summary>
        double v;

        constexpr HSV_ operator +(const HSV_& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h + other.h),
                Math::Saturate(s + other.s),
                Math::Saturate(v + other.v)
            };
        }
        constexpr HSV_& operator +=(const HSV_& other) noexcept
        {
            *this = (*this) + other;
            return *this;
        }
        constexpr HSV_ operator -(const HSV_& other) const noexcept
        {
            return{
                ColorUtil::RepeatHue360(h - other.h),
                Math::Saturate(s - other.s),
                Math::Saturate(v - other.v)
            };
        }
        constexpr HSV_& operator -=(const HSV_& other) noexcept
        {
            *this = (*this) - other;
            return *this;
        }
        friend constexpr bool operator==(const HSV_& a, const HSV_& b) = default;
    };

    /// <summary>
    /// HSV (円錐モデル)
    /// </summary>
    using HSVCone = HSV_<struct Cone>;

    /// <summary>
    /// HSV (円柱モデル)
    /// </summary>
    using HSVCylinder = HSV_<struct Cylinder>;

    using HSV = HSVCylinder;
}
