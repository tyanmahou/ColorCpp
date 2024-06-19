export module ColorCpp:CastDisplayP3;
import :ColorCastTrait;
import :RGB;
import :DisplayP3;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<DisplayP3>
    {
        using depend_type = RGB;
    };
    // DisplayP3 <=> RGB
    template<>
    struct ColorCastTraits<RGB, DisplayP3>
    {
        constexpr static DisplayP3 Cast(const RGB& rgb)
        {
            return
            {
            };
        }
    };
    template<>
    struct ColorCastTraits<DisplayP3, RGB>
    {
        constexpr static RGB Cast(const DisplayP3& p3)
        {
            return
            {
            };
        }
    };
}
