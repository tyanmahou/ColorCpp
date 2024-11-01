export module ColorCpp:CastA98;
import :ColorCastTrait;

import :A98;
import :XYZ;
import :Constants;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<A98>
    {
        using depend_type = XYZ;
    };

    // A98 <=> XYZ
    template<>
    struct ColorCastTraits<A98, XYZ>
    {
        constexpr static A98 Cast(const XYZ& xyz)
        {
            const auto& [x, y, z] = xyz;
            double r = 2.0415879038107465 * x - 0.5650069742788597 * y - 0.3447313507783297 * z;
            double g = -0.9692436362808798 * x + 1.8759675015077206 * y + 0.0415550574071756 * z;
            double b = 0.0134442806320312 * x - 0.1183623922310184 * y + 1.0151749943912058 * z;
            return {
                .r = InternalUtil::Gamma(r, AdobeGamma),
                .g = InternalUtil::Gamma(g, AdobeGamma),
                .b = InternalUtil::Gamma(b, AdobeGamma),
            };
        }
    };
    template<>
    struct ColorCastTraits<XYZ, A98>
    {
        constexpr static XYZ Cast(const A98& rgb)
        {
            double r = InternalUtil::Gamma(rgb.r, AdobeGammaInv);
            double g = InternalUtil::Gamma(rgb.g, AdobeGammaInv);
            double b = InternalUtil::Gamma(rgb.b, AdobeGammaInv);
            return {
                .x = 0.5766690429101305 * r + 0.1855582379065463 * g + 0.1882286462349947 * b,
                .y = 0.297344975250536 * r + 0.6273635662554661 * g + 0.0752914584939979 * b,
                .z = 0.0270313613864123 * r + 0.0706888525358272 * g + 0.9913375368376386 * b,
            };
        }
    };
}
