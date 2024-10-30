export module ColorCpp:DiffHWB;
import :ColorDiffTrait;
import :HWB;
import :Math;
import :InternalUtil;

export namespace colorcpp
{
    template<>
    struct ColorDiffTrait<HWB>
    {
        constexpr static double Diff(const HWB& a, const HWB& b)
        {
            const double _h = InternalUtil::DiffHue(a.h, b.h);
            const double _w = a.w - b.w;
            const double _b = a.b - b.b;
            return Math::Sqrt(
                _h * _h
                + _w * _w
                + _b * _b
            );
        }
    };
}
