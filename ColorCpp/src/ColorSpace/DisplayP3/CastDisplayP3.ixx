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
}
