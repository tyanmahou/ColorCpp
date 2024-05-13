export module ColorCpp:ColorUtil;
import :Math;

export namespace colorcpp
{
    class ColorUtil
    {
    public:
        [[nodiscard]] static constexpr inline double RepeatHue360(double h) noexcept
        {
            return Math::Repeat(h, 360.0);
        }
    };
}
