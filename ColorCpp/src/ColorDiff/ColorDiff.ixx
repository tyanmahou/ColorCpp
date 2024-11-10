export module ColorCpp:ColorDiff;
export import :ColorDiffTrait;
export import :ColorDiff.CIE76;
export import :ColorDiff.CIE94;
export import :ColorDiff.CIE2000;
export import :ColorDiff.CMC;
export import :ColorDiff.Euclidean;

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
        [[nodiscard]] static constexpr double Euclidean(const T& a, const U& b)
        {
            return EuclideanDiff<Type>{}(a, b);
        }
        template<class T, class U>
        [[nodiscard]] static constexpr double CIE76(const T& a, const U& b)
        {
            return CIE76Diff{}(a, b);
        }
        template<class T,  class U>
        [[nodiscard]] static constexpr double CIE94(const T& a, const U& b)
        {
            return CIE94Diff{}(a, b);
        }

        [[nodiscard]] static constexpr CIE94Diff CIE94(double kL, double k1, double k2)
        {
            return CIE94Diff{ kL, k1, k2 };
        }

        template<class T, class U>
        [[nodiscard]] static constexpr double CIE94_GraphicArts(const T& a, const U& b)
        {
            return CIE94Diff_GraphicArts(a, b);
        }
        template<class T, class U>
        [[nodiscard]] static constexpr double CIE94_Textiles(const T& a, const U& b)
        {
            return CIE94Diff_Textiles(a, b);
        }

        template<class T, class U>
        [[nodiscard]] static constexpr double CIE2000(const T& a, const U& b)
        {
            return CIE2000Diff{}(a, b);
        }
        [[nodiscard]] static constexpr CIE2000Diff CIE2000(double kL, double kC, double kH)
        {
            return CIE2000Diff{ kL, kC, kH };
        }

        template<class T, class U>
        [[nodiscard]] static constexpr double CMC(const T& a, const U& b)
        {
            return CMCDiff{}(a, b);
        }
        [[nodiscard]] static constexpr CMCDiff CMC(double l, double c)
        {
            return CMCDiff{ l, c };
        }
    };
}
