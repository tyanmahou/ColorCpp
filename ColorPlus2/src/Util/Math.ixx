export module ColorPlus2:Math;
import <algorithm>;
import <cmath>;

export namespace cp2
{
	constexpr inline double Min(double x, double y) noexcept
	{
		return std::min(x, y);
	}
	constexpr inline double Max(double x, double y) noexcept
	{
		return std::max(x, y);
	}
	constexpr inline double Min(double x, double y, double z) noexcept
	{
		return std::min(x, std::min(y, z));
	}
	constexpr inline double Max(double x, double y, double z) noexcept
	{
		return std::max(x, std::max(y, z));
	}
	// TODO: C++26でconstexpr対応
	constexpr inline auto Sqrt(auto x) noexcept
	{
		return std::sqrt(x);
	}
	// TODO: C++26でconstexpr対応
	constexpr inline auto Pow(auto x, auto y) noexcept
	{
		return std::pow(x, y);
	}
	// TODO: C++26でconstexpr対応
	constexpr inline auto Cbrt(auto x) noexcept
	{
		return std::cbrt(x);
	}
}