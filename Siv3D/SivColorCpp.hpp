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
		constexpr static s3d::ColorF Cast(const RGBA& from)
		{
			auto&& [r, g, b, a] = from;
			return { r, g, b, a };
		}
	};
	template<>
	struct ColorCastTraits<RGBA, s3d::ColorF>
	{
		constexpr static RGBA Cast(const s3d::ColorF& from)
		{
			auto&& [r, g, b, a] = from;
			return { r, g, b, a };
		}
	};

	// Color
	template<>
	struct ColorCastTraits<s3d::Color, RGBA32>
	{
		constexpr static s3d::Color Cast(const RGBA32& from)
		{
			auto&& [r, g, b, a] = from;
			return { r, g, b, a };
		}
	};
	template<>
	struct ColorCastTraits<RGBA32, s3d::Color>
	{
		constexpr static RGBA32 Cast(const s3d::Color& from)
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

	// HSV
	template<>
	struct ColorCastTraits<s3d::HSV, colorcpp::HSV>
	{
		constexpr static s3d::HSV Cast(const colorcpp::HSV& from)
		{
			return { from.h, from.s, from.v };
		}
	};
	template<>
	struct ColorCastTraits<colorcpp::HSV, s3d::HSV>
	{
		constexpr static colorcpp::HSV Cast(const s3d::HSV& from)
		{
			return { from.h, from.s, from.v };
		}
	};
	template<>
	struct ColorCastDependency<s3d::HSV>
	{
		using depend_type = colorcpp::HSV;
	};
}
