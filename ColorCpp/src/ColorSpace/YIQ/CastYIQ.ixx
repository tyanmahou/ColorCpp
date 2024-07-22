export module ColorCpp:CastYIQ;
import :ColorCastTrait;

import :RGB;
import :YIQ;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<YIQ>
    {
        using depend_type = RGB;
    };
}
