export module ColorPlus2:CastHSV;
import :ColorCastTrait;
import :RGB;
import :HSV;
import :Math;
import <algorithm>;

export namespace colorp2
{
	template<>
	struct ColorCastDependency<HSV>
	{
		using depend_type = RGB;
	};

	// HSV <=> RGB
	template<>
	struct ColorCastTraits<HSV, RGB>
	{
		constexpr static HSV Cast(const RGB& rgb)
		{
			// Fast HSV to RGB
			auto [r, g, b] = rgb;
			double k = 0;
			if (g < b) {
				std::swap(g, b);
				k = -1;
			}
			if (r < g) {
				std::swap(r, g);
				k = -2.0 / 6 - k;
			}
			double c = r - Math::Min(g, b);
			return HSV{
				.h = 360.0 * Math::Abs(k + (g - b) / (6 * c + 1e-20)),
				.s = c / (r + 1e-20),
				.v = r
			};
		}
	};
	template<>
	struct ColorCastTraits<RGB, HSV>
	{
		constexpr static RGB Cast(const HSV& hsv)
		{
			auto [h, s, v] = hsv;
			h /= 360.0;
			h = Math::Fraction(h);

			double r = Math::Abs(h * 6 - 3) - 1;
			double g = 2 - Math::Abs(h * 6 - 2);
			double b = 2 - Math::Abs(h * 6 - 4);

			r = ((Math::Saturate(r) - 1) * s + 1) * v;
			g = ((Math::Saturate(g) - 1) * s + 1) * v;
			b = ((Math::Saturate(b) - 1) * s + 1) * v;

			return RGB{
				.r = r,
				.g = g,
				.b = b
			};
		}
	};
}