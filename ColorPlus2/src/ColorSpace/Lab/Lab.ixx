export module ColorPlus2:Lab;

export namespace colorp2
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
}