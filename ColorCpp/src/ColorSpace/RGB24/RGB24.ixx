export module ColorCpp:RGB24;
import :Type;

export namespace colorcpp
{
    /// <summary>
    /// sRGB Alpha
    /// </summary>
    struct RGB24
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

        [[nodiscard]] friend constexpr bool operator==(const RGB24& a, const RGB24& b) = default;
    };
}
