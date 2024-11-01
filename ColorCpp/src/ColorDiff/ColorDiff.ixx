export module ColorCpp:ColorDiff;
export import :ColorDiffTrait;
export import :ColorDiff.Euclidean;
export import :ColorDiff.CIE76;
export import :ColorDiff.CIE94;
export import :ColorDiff.CMC;

export import :DiffA98;
export import :DiffCMY;
export import :DiffCMYK;
export import :DiffDisplayP3;
export import :DiffHex;
export import :DiffHSI;
export import :DiffHSL;
export import :DiffHSV;
export import :DiffHunterLab;
export import :DiffHWB;
export import :DiffITP;
export import :DiffLab;
export import :DiffLCH;
export import :DiffLRGB;
export import :DiffLuv;
export import :DiffOkLab;
export import :DiffOkLCH;
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
        template<class Type = RGB, class T, class U>
        static constexpr double Euclidean(const T& a, const U& b)
        {
            return EuclideanDiff<Type>{}(a, b);
        }
        template<class T, class U>
        static constexpr double CIE76(const T& a, const U& b)
        {
            return CIE76Diff{}(a, b);
        }
        template<class T,  class U>
        static constexpr double CIE94(const T& a, const U& b)
        {
            return CIE94Diff{}(a, b);
        }
        template<
            double kL,
            double k1,
            double k2,
            class T,
            class U
        >
        static constexpr double CIE94(const T& a, const U& b)
        {
            return CIE94Diff{ kL, k1, k2 }(a, b);
        }
        template<class T, class U>
        static constexpr double CIE94_GraphicArts(const T& a, const U& b)
        {
            return CIE94Diff_GraphicArts(a, b);
        }
        template<class T, class U>
        static constexpr double CIE94_Textiles(const T& a, const U& b)
        {
            return CIE94Diff_Textiles(a, b);
        }

        template<class T, class U>
        static constexpr double CMC(const T& a, const U& b)
        {
            return CMCDiff{}(a, b);
        }
        template<
            double l,
            double c,
            class T,
            class U
        >
        static constexpr double CMC(const T& a, const U& b)
        {
            return CMCDiff{l, c}(a, b);
        }
    };
}
