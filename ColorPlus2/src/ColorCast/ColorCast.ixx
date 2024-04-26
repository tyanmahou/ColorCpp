export module ColorPlus2:ColorCast;
import :RGB;
import :RYB;

export namespace cp2
{
    template<class To, class From>
    inline constexpr To ColorCast(const From& from);

    template RYB ColorCast<RYB, RGB>(const RGB& rgb);
    template RGB ColorCast<RGB, RYB>(const RYB& ryb);
}
