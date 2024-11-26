#pragma once
import ColorCpp;

namespace colorcpp
{
    // ColorF
    template<>
    struct ColorCastDependency<s3d::ColorF>
    {
        using depend_type = RGBA;
    };

    template<>
    struct ColorCastTraits<s3d::ColorF, RGBA>
    {
        [[nodiscard]] constexpr static s3d::ColorF Cast(const RGBA& from)
        {
            auto&& [r, g, b, a] = from;
            return { r, g, b, a };
        }
    };
    template<>
    struct ColorCastTraits<RGBA, s3d::ColorF>
    {
        [[nodiscard]] constexpr static RGBA Cast(const s3d::ColorF& from)
        {
            auto&& [r, g, b, a] = from;
            return { r, g, b, a };
        }
    };
    template<>
    struct ColorDiffTrait<s3d::ColorF>
    {
        [[nodiscard]] static double Diff(const s3d::ColorF& left, const s3d::ColorF& right)
        {
            return ColorDiff::Euclidean<RGBA>(left, right);
        }
    };
    // Color
    template<>
    struct ColorCastTraits<s3d::Color, RGBA32>
    {
        [[nodiscard]] constexpr static s3d::Color Cast(const RGBA32& from)
        {
            auto&& [r, g, b, a] = from;
            return { r, g, b, a };
        }
    };
    template<>
    struct ColorCastTraits<RGBA32, s3d::Color>
    {
        [[nodiscard]] constexpr static RGBA32 Cast(const s3d::Color& from)
        {
            auto&& [r, g, b, a] = from;
            return { r, g, b, a };
        }
    };
    template<>
    struct ColorCastDependency<s3d::Color>
    {
        using depend_type = RGBA32;
    };
    template<>
    struct ColorDiffTrait<s3d::Color>
    {
        [[nodiscard]] static double Diff(const s3d::Color& left, const s3d::Color& right)
        {
            return ColorDiff::Euclidean<RGBA32>(left, right);
        }
    };
    // HSV
    template<>
    struct ColorCastTraits<s3d::HSV, colorcpp::HSV>
    {
        [[nodiscard]] constexpr static s3d::HSV Cast(const colorcpp::HSV& from)
        {
            return { from.h, from.s, from.v };
        }
    };
    template<>
    struct ColorCastTraits<colorcpp::HSV, s3d::HSV>
    {
        [[nodiscard]] constexpr static colorcpp::HSV Cast(const s3d::HSV& from)
        {
            return { from.h, from.s, from.v };
        }
    };
    template<>
    struct ColorCastDependency<s3d::HSV>
    {
        using depend_type = colorcpp::HSV;
    };
    template<>
    struct ColorDiffTrait<s3d::HSV>
    {
        [[nodiscard]] static double Diff(const s3d::HSV& left, const s3d::HSV& right)
        {
            return ColorDiff::Euclidean<colorcpp::HSV>(left, right);
        }
    };
}
