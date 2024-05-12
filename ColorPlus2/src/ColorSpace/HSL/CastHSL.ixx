export module ColorPlus2:CastHSL;
import :ColorCastTrait;
import :RGB;
import :HSL;
import :Math;

export namespace colorp2
{
	// HSL <=> RGB
	template<>
	struct ColorCastTraits<HSL, RGB>
	{
		constexpr static HSL Cast(const RGB& rgb)
		{
			const auto& [r, g, b] = rgb;
			double cmax = Math::Max(r, g, b);
			double cmin = Math::Min(r, g, b);
			double delta = cmax - cmin;

			double h = 0;
			double s = 0;
			double l = (cmax + cmin) / 2.0;
			if (delta != 0) {
				s = (l < 0.5) ? delta / (cmax + cmin) : delta / (2.0 - cmax - cmin);

				if (cmax == r) {
					h = (g - b) / delta;
				} else if (cmax == g) {
					h = (b - r) / delta + 2;
				} else if (cmax == b) {
					h = (r - g) / delta + 4;
				}
				h = Math::RepeatHue360(h * 60);
			}
			return HSL{
				.h = h,
				.s = s,
				.l = l
			};
		}
	};
	template<>
	struct ColorCastTraits<RGB, HSL>
	{
		constexpr static RGB Cast(const HSL& hsl)
		{
			const auto& [h, s, l] = hsl;

			if (s == 0) {
				return RGB {l, l, l};
			}

			double h1 = h / 360.0;
			double max = (l < 0.5) ? (l * (1 + s)) : (l + s - (s * l));
			double min = 2 * l - max;

			double r = HueToRGB(min, max, h1 + 1/ 3.0);
			double g = HueToRGB(min, max, h1);
			double b = HueToRGB(min, max, h1 - 1/ 3.0);

			return RGB{
				.r = r,
				.g = g,
				.b = b
			};
		}

		constexpr static double HueToRGB(double min, double max, double h)
		{
			if (h < 0) {
				h += 1;
			}
			if (h > 1) {
				h -= 1;
			}
			if (6 * h < 1) {
				return min + (max - min) * 6 * h;
			}
			if (2 * h < 1) {
				return max;
			}
			if (3 * h < 2) {
				return min + (max - min) * (2.0 / 3.0 - h) * 6;
			}
			return min;

		}
	};

	// HSL <=> OTHER
	template<class From>
	struct ColorCastTraits<HSL, From>
	{
		constexpr static HSL Cast(const From& from)
		{
			return ColorCast<HSL>(ColorCast<RGB>(from));
		}
	};
}