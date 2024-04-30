export module ColorPlus2:XYZ;

export namespace cp2
{
	/// <summary>
	/// XYZ色空間
	/// 0～1
	/// </summary>
	struct XYZ
	{
		/// <summary>
		/// X 0～1
		/// </summary>
		double x;

		/// <summary>
		/// Y 0～1
		/// </summary>
		double y;

		/// <summary>
		/// Z 0～1
		/// </summary>
		double z;

		friend constexpr bool operator==(const XYZ& a, const XYZ& b) = default;
	};
}