﻿export module ColorCpp:CastXYZ;
import :ColorCastTrait;

import :LRGB;
import :XYZ;

export namespace colorcpp
{
    template<class Illuminant>
    struct ColorCastDependency<XYZ_<Illuminant>>
    {
        using depend_type = LRGB;
    };

    // XYZ65 <=> LRGB
    template<>
    struct ColorCastTraits<XYZ65, LRGB>
    {
        [[nodiscard]] constexpr static XYZ65 Cast(const LRGB& rgb)
        {
            const auto& [r, g, b] = rgb;
            return {
                .x = 0.4123907992659593 * r + 0.357584339383878 * g + 0.1804807884018343 * b,
                .y = 0.2126390058715102 * r + 0.715168678767756 * g + 0.0721923153607337 * b,
                .z = 0.0193308187155918 * r + 0.119194779794626 * g + 0.9505321522496607 * b,
            };
        }
    };
    template<>
    struct ColorCastTraits<LRGB, XYZ65>
    {
        [[nodiscard]] constexpr static LRGB Cast(const XYZ65& xyz)
        {
            return LRGB{
                .r = 3.2409699419045226 * xyz.x - 1.5373831775700939 * xyz.y - 0.4986107602930034 * xyz.z,
                .g = -0.9692436362808796 * xyz.x + 1.8759675015077204 * xyz.y + 0.0415550574071756 * xyz.z,
                .b = 0.0556300796969936 * xyz.x - 0.2039769588889765 * xyz.y + 1.0569715142428784 * xyz.z
            };
        }
    };

    // XYZ50 <=> LRGB
    template<>
    struct ColorCastTraits<XYZ50, LRGB>
    {
        [[nodiscard]] constexpr static XYZ50 Cast(const LRGB& rgb)
        {
            const auto& [r, g, b] = rgb;
            return {
                .x = 0.436065742824811 * r + 0.3851514688337912 * g + 0.14307845442264197 * b,
                .y = 0.22249319175623702 * r + 0.7168870538238823 * g + 0.06061979053616537 * b,
                .z = 0.013923904500943465 * r + 0.09708128566574634 * g + 0.7140993584005155 * b,
            };
        }
    };
    template<>
    struct ColorCastTraits<LRGB, XYZ50>
    {
        [[nodiscard]] constexpr static LRGB Cast(const XYZ50& xyz)
        {
            return LRGB{
                .r = 3.1341359569958707 * xyz.x - 1.6173863321612538 * xyz.y - 0.4906619460083532 * xyz.z,
                .g = -0.978795502912089 * xyz.x + 1.916254567259524 * xyz.y + 0.03344273116131949 * xyz.z,
                .b = 0.07195537988411677 * xyz.x - 0.2289768264158322 * xyz.y + 1.405386058324125 * xyz.z
            };
        }
    };

    // XYZ65 <=> XYZ50
    template<>
    struct ColorCastTraits<XYZ65, XYZ50>
    {
        [[nodiscard]] constexpr static XYZ65 Cast(const XYZ50& xyz)
        {
            return {
                .x = 0.955473421488075 * xyz.x - 0.02309845494876471 * xyz.y + 0.06325924320057072 * xyz.z,
                .y = -0.0283697093338637 * xyz.x + 1.0099953980813041 * xyz.y + 0.021041441191917323 * xyz.z,
                .z = 0.012314014864481998 * xyz.x - 0.020507649298898964 * xyz.y + 1.330365926242124 * xyz.z
            };
        }
    };
    template<>
    struct ColorCastTraits<XYZ50, XYZ65>
    {
        [[nodiscard]] constexpr static XYZ50 Cast(const XYZ65& xyz)
        {
            return {
                .x = 1.0479297925449969 * xyz.x + 0.022946870601609652 * xyz.y - 0.05019226628920524 * xyz.z,
                .y = 0.02962780877005599 * xyz.x + 0.9904344267538799 * xyz.y - 0.017073799063418826 * xyz.z,
                .z = -0.009243040646204504 * xyz.x + 0.015055191490298152 * xyz.y + 0.7518742814281371 * xyz.z
            };
        }
    };
}
