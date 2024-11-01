export module ColorCpp:DiffHex;
import :ColorDiffTrait;
import :CastHex;
import :DiffRGBA32;
import :Hex;
import :RGBA32;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<Hex>
    {
        [[nodiscard]] constexpr static double Diff(const Hex& a, const Hex& b)
        {
            RGBA32 a2 = ColorCastTraits<RGBA32, Hex>::Cast(a);
            RGBA32 b2 = ColorCastTraits<RGBA32, Hex>::Cast(b);
            return ColorDiffTrait<RGBA32>::Diff(a2, b2);
        }
    };
}
