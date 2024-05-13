export module ColorCpp:CastRGBA32;
import :ColorCastTrait;
import :RGBA32;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<RGBA32>
    {
        using depend_type = void;
    };
}
