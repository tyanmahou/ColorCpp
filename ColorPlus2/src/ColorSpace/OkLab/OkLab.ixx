export module ColorPlus2:OkLab;

export namespace cp2
{
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