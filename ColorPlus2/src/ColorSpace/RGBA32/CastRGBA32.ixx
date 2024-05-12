export module ColorPlus2:CastRGBA32;
import :ColorCastTrait;
import :RGBA32;

export namespace colorp2
{
    template<>
    struct ColorCastDependency<RGBA32>
    {
        using depend_type = void;
    };
}