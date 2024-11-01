export module ColorCpp:DiffRGB24;
import :ColorDiffTrait;
import :RGB24;
import :Math;
import :Type;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGB24>
    {
        [[nodiscard]] constexpr static double Diff(const RGB24& a, const RGB24& b)
        {
            const int32 _r = static_cast<int32>(a.r) - static_cast<int32>(b.r);
            const int32 _g = static_cast<int32>(a.g) - static_cast<int32>(b.g);
            const int32 _b = static_cast<int32>(a.b) - static_cast<int32>(b.b);
            return Math::Sqrt(
                _r * _r
                + _g * _g
                + _b * _b
            );
        }
    };
}
