export module ColorPlus2:XYZ;

export namespace colorp2
{
	/// <summary>
	/// XYZ色空間
	/// 0～1
	/// </summary>
	template<class WhitePointTag>
	struct XYZBase
	{
		/// <summary>
		/// X [0, 1]
		/// </summary>
		double x;

		/// <summary>
		/// Y [0, 1]
		/// </summary>
		double y;

		/// <summary>
		/// Z [0, 1]
		/// </summary>
		double z;

		friend constexpr bool operator==(const XYZBase& a, const XYZBase& b) = default;
	};

	using XYZ50 = XYZBase<struct XYZ_D50>;
	using XYZ65 = XYZBase<struct XYZ_D65>;

	template<class XYZ_>
	inline constexpr XYZ_ WhitePoint{1, 1, 1};

	template<>
	inline constexpr XYZ50 WhitePoint<XYZ50>{ 0.96419503, 1.0, 0.82511874};

	template<>
	inline constexpr XYZ65 WhitePoint<XYZ65>{ 0.950456, 1.0, 1.088754 };
}