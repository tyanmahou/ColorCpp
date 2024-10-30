export module ColorCpp:ColorDiff;
export import :ColorDiffTrait;
export import :ColorDiff.Euclidean;

export import :DiffA98;
export import :DiffCMY;
export import :DiffCMYK;
export import :DiffDisplayP3;
export import :DiffHex;
export import :DiffHSI;
export import :DiffProphoto;
export import :DiffRec2020;

export import :DiffRGB;
export import :DiffRGB24;
export import :DiffRGBA;
export import :DiffRGBA32;
export import :DiffRYB;
export import :DiffXyY;
export import :DiffXYZ;
export import :DiffYIQ;
import :RGB;

export namespace colorcpp
{
    struct ColorDiff
    {
    public:
        template<class Type>
        inline static constexpr EuclideanDiff<Type> Euclidean = {};
    };
}
