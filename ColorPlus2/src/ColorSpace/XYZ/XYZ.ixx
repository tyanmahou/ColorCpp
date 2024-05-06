export module ColorPlus2:XYZ;

export namespace cp2
{
	/// <summary>
	/// XYZ色空間(D65)
	/// 0～1
	/// </summary>
	struct XYZ
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

		friend constexpr bool operator==(const XYZ& a, const XYZ& b) = default;
	};

	inline constexpr XYZ D50{ 0.96419503 ,1.0,0.82511874 };
	inline constexpr XYZ D65{ 0.950456 , 1.0 , 1.088754 };
}