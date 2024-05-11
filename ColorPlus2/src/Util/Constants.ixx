export module ColorPlus2:Constants;

import :XYZ;

export namespace cp2
{
	inline constexpr XYZ D50{ 0.96419503 ,1.0,0.82511874 };
	inline constexpr XYZ D65{ 0.950456 , 1.0 , 1.088754 };
	inline constexpr double Epsilon = 0.008856451679;
	inline constexpr double Kappa = 903.296296296;
}