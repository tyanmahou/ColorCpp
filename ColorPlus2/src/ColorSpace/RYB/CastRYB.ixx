export module ColorPlus2:CastRYB;
import :ColorCastTrait;

import :RGB;
import :RYB;
import :Math;

export namespace colorp2
{
	template<>
	struct ColorCastDependency<RYB>
	{
		using depend_type = RGB;
	};

	// RYB <=> RGB
	template<>
	struct ColorCastTraits<RYB, RGB>
	{
		constexpr static RYB Cast(const RGB& rgb)
		{
			auto&& [R, G, B] = rgb;
			const double Iw = Math::Min(R, G, B);
			const double rRGB = R - Iw;
			const double gRGB = G - Iw;
			const double bRGB = B - Iw;

			const double yRGB = Math::Min(rRGB, gRGB);
			const double rRYB = rRGB - yRGB;
			const double yRYB = (yRGB + gRGB) / 2.0;
			const double bRYB = (bRGB + gRGB - yRGB) / 2.0;

			const double maxRGB = Math::Max(rRGB, gRGB, bRGB);
			const double maxRYB = Math::Max(rRYB, yRYB, bRYB);

			const double n = maxRYB == 0 ? 1.0 : maxRGB / maxRYB;

			const double rRYB_ = rRYB * n;
			const double yRYB_ = yRYB * n;
			const double bRYB_ = bRYB * n;

			const double Ib = Math::Min(1 - R, 1 - G, 1 - B);
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
			auto&& [R, Y, B] = ryb;
			const double Ib = Math::Min(R, Y, B);
			const double rRYB = R - Ib;
			const double yRYB = Y - Ib;
			const double bRYB = B - Ib;

			const double gRYB = Math::Min(yRYB, bRYB);
			const double rRGB = rRYB + yRYB - gRYB;
			const double gRGB = yRYB + gRYB;
			const double bRGB = 2.0 * (bRYB - gRYB);

			const double maxRGB = Math::Max(rRGB, gRGB, bRGB);
			const double maxRYB = Math::Max(rRYB, yRYB, bRYB);

			const double n = maxRGB == 0 ? 1.0 : maxRYB / maxRGB;

			const double rRGB_ = rRGB * n;
			const double gRGB_ = gRGB * n;
			const double bRGB_ = bRGB * n;

			const double Iw = Math::Min(1 - R, 1 - Y, 1 - B);
			return {
				rRGB_ + Iw,
				gRGB_ + Iw,
				bRGB_ + Iw,
			};
		}
	};
}