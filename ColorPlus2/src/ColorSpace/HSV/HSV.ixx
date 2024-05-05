export module ColorPlus2:HSV;
import :Math;

export namespace cp2
{
	/// <summary>
	/// HSV
	/// </summary>
	struct HSV
	{
		/// <summary>
		/// 色相 [0, 360)
		/// </summary>
		double h;

		/// <summary>
		/// 彩度 [0, 1]
		/// </summary>
		double s;

		/// <summary>
		/// 明度 [0, 1]
		/// </summary>
		double v;

		constexpr HSV operator +(const HSV& other) const noexcept
		{
			return{
				Math::RepeatHue360(h + other.h), 
				Math::Saturate(s + other.s),
				Math::Saturate(v + other.v)
			};
		}
		constexpr HSV& operator +=(const HSV& other) noexcept
		{
			*this = (*this) + other;
			return *this;
		}
		constexpr HSV operator -(const HSV& other) const noexcept
		{
			return{
				Math::RepeatHue360(h - other.h),
				Math::Saturate(s - other.s),
				Math::Saturate(v - other.v)
			};
		}
		constexpr HSV& operator -=(const HSV& other) noexcept
		{
			*this = (*this) - other;
			return *this;
		}
		friend constexpr bool operator==(const HSV& a, const HSV& b) = default;
	};
}