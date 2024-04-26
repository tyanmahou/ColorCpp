export module ColorPlus2:ColorCast;
import :RGB;
import :RYB;
import :Math;

export namespace cp2
{
	template<class To, class From>
	struct ColorCastTraits
	{
		//static constexpr To Cast(const From& from);
	};
	template<class T>
	struct ColorCastTraits<T, T>
	{
		static constexpr T Cast(const T& from)
		{
			return from;
		}
	};
	template<>
	struct ColorCastTraits<RYB, RGB>
	{
		constexpr static RYB Cast(const RGB& rgb)
		{
			auto [R, G, B] = rgb;
			const double Iw = Min(R, G, B);
			const double rRGB = R - Iw;
			const double gRGB = G - Iw;
			const double bRGB = B - Iw;

			const double yRGB = Min(rRGB, gRGB);
			const double rRYB = rRGB - yRGB;
			const double yRYB = (yRGB + gRGB) / 2.0;
			const double bRYB = (bRGB + gRGB - yRGB) / 2.0;

			const double maxRGB = Max(rRGB, gRGB, bRGB);
			const double maxRYB = Max(rRYB, yRYB, bRYB);

			const double n = maxRYB == 0 ? 1.0 : maxRGB / maxRYB;

			const double rRYB_ = rRYB * n;
			const double yRYB_ = yRYB * n;
			const double bRYB_ = bRYB * n;

			const double Ib = Min(1 - R, 1 - G, 1 - B);
			return {
				.r = rRYB_ + Ib,
				.y = yRYB_ + Ib,
				.b = bRYB_ + Ib,
			};
		}
	};

	template<>
	struct ColorCastTraits<RGB, RYB>
	{
		constexpr static RGB Cast(const RYB& ryb)
		{
			auto [R, Y, B] = ryb;
			const double Ib = Min(R, Y, B);
			const double rRYB = R - Ib;
			const double yRYB = Y - Ib;
			const double bRYB = B - Ib;

			const double gRYB = Min(yRYB, bRYB);
			const double rRGB = rRYB + yRYB - gRYB;
			const double gRGB = yRYB + gRYB;
			const double bRGB = 2.0 * (bRYB - gRYB);

			const double maxRGB = Max(rRGB, gRGB, bRGB);
			const double maxRYB = Max(rRYB, yRYB, bRYB);

			const double n = maxRGB == 0 ? 1.0 : maxRYB / maxRGB;

			const double rRGB_ = rRGB * n;
			const double gRGB_ = gRGB * n;
			const double bRGB_ = bRGB * n;

			const double Iw = Min(1 - R, 1 - Y, 1 - B);
			return {
				rRGB_ + Iw,
				gRGB_ + Iw,
				bRGB_ + Iw,
			};
		}
	};
	
    template<class To, class From>
	inline constexpr To ColorCast(const From& from)
	{
		return ColorCastTraits<To, From>::Cast(from);
	}
}
