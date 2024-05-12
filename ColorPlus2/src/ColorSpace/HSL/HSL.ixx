export module ColorPlus2:HSL;
import :Math;

export namespace colorp2
{
	/// <summary>
	/// HSL (円柱モデル)
	/// </summary>
	struct HSL
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
		/// 輝度 [0, 1]
		/// </summary>
		double l;

		constexpr HSL operator +(const HSL& other) const noexcept
		{
			return{
				Math::RepeatHue360(h + other.h),
				Math::Saturate(s + other.s),
				Math::Saturate(l + other.l)
			};
		}
		constexpr HSL& operator +=(const HSL& other) noexcept
		{
			*this = (*this) + other;
			return *this;
		}
		constexpr HSL operator -(const HSL& other) const noexcept
		{
			return{
				Math::RepeatHue360(h - other.h),
				Math::Saturate(s - other.s),
				Math::Saturate(l - other.l)
			};
		}
		constexpr HSL& operator -=(const HSL& other) noexcept
		{
			*this = (*this) - other;
			return *this;
		}
		friend constexpr bool operator==(const HSL& a, const HSL& b) = default;
	};

	/// <summary>
	/// HSB
	/// </summary>
	using HSB = HSL;
}