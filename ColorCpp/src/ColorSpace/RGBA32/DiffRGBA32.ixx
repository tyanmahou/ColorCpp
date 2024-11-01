export module ColorCpp:DiffRGBA32;
import :ColorDiffTrait;
import :RGBA32;
import :Math;
import :Type;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<RGBA32>
    {
        [[nodiscard]] constexpr static double Diff(const RGBA32& a, const RGBA32& b)
        {
            const int32 _r = static_cast<int32>(a.r) - static_cast<int32>(b.r);
            const int32 _g = static_cast<int32>(a.g) - static_cast<int32>(b.g);
            const int32 _b = static_cast<int32>(a.b) - static_cast<int32>(b.b);
            const int32 _a = static_cast<int32>(a.a) - static_cast<int32>(b.a);
            return Math::Sqrt(
                _r * _r
                + _g * _g
                + _b * _b
                + _a * _a
            );
        }
    };
}
