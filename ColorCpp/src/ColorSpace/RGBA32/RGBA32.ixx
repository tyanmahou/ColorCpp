export module ColorCpp:RGBA32;
import :Type;

export namespace colorcpp
{
    /// <summary>
    /// sRGB Alpha
    /// </summary>
    struct RGBA32
    {
        using value_type = uint8;

        /// <summary>
        /// Red [0, 255]
        /// </summary>
        value_type r;

        /// <summary>
        /// Green [0, 255]
        /// </summary>
        value_type g;

        /// <summary>
        /// Blue [0, 255]
        /// </summary>
        value_type b;

        /// <summary>
        /// Alpha [0, 255]
        /// </summary>
        value_type a;

        [[nodiscard]] friend constexpr bool operator==(const RGBA32& a, const RGBA32& b) = default;
    };
}
