export module ColorCpp:CastHex;
import :ColorCastTrait;
import :RGBA32;
import :Hex;
import :Type;

export namespace colorcpp
{
    template<>
    struct ColorCastDependency<Hex>
    {
        using depend_type = RGBA32;
    };

    // RGBA32 <=> Hex
    template<>
    struct ColorCastTraits<RGBA32, Hex>
    {
        [[nodiscard]] constexpr static RGBA32 Cast(const Hex& hex)
        {
            auto hexView = hex.hexView();

            return RGBA32{
                .r = static_cast<uint8>(HexToDecimal(hexView[0]) * 16 + HexToDecimal(hexView[1])),
                .g = static_cast<uint8>(HexToDecimal(hexView[2]) * 16 + HexToDecimal(hexView[3])),
                .b = static_cast<uint8>(HexToDecimal(hexView[4]) * 16 + HexToDecimal(hexView[5])),
                .a = static_cast<uint8>(HexToDecimal(hexView[6]) * 16 + HexToDecimal(hexView[7]))
            };
        }
    };
    template<>
    struct ColorCastTraits<Hex, RGBA32>
    {
        [[nodiscard]] constexpr static Hex Cast(const RGBA32& rgba)
        {
            const auto& [r, g, b, a] = rgba;
            char hex[8] = {
                DecimalToHex(r >> 4),
                DecimalToHex(r & 0x0F),
                DecimalToHex(g >> 4),
                DecimalToHex(g & 0x0F),
                DecimalToHex(b >> 4),
                DecimalToHex(b & 0x0F),
                DecimalToHex(a >> 4),
                DecimalToHex(a & 0x0F)
            };
            return Hex{ std::string_view{hex, 8} };
        }
    };
}
