export module ColorPlus2:Math;
import <algorithm>;

export namespace cp2
{
	constexpr inline double Min(double x, double y)
	{
		return std::min(x, y);
	}
	constexpr inline double Max(double x, double y)
	{
		return std::max(x, y);
	}
	constexpr inline double Min(double x, double y, double z)
	{
		return std::min(x, std::min(y, z));
	}
	constexpr inline double Max(double x, double y, double z)
	{
		return std::max(x, std::max(y, z));
	}
}