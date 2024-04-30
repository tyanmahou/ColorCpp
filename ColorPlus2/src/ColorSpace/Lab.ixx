export module ColorPlus2:Lab;

export namespace cp2
{
	/// <summary>
	/// Lab色空間
	/// </summary>
	struct Lab
	{
		double l;
		double a;
		double b;

		friend constexpr bool operator==(const Lab& a, const Lab& b) = default;
	};

	/// <summary>
	/// Hunter Lab色空間
	/// </summary>
	struct HunterLab
	{
		double l;
		double a;
		double b;

		friend constexpr bool operator==(const HunterLab& a, const HunterLab& b) = default;
	};

	/// <summary>
	/// Ok Lab色空間
	/// </summary>
	struct OkLab
	{
		double l;
		double a;
		double b;

		friend constexpr bool operator==(const OkLab& a, const OkLab& b) = default;
	};
}