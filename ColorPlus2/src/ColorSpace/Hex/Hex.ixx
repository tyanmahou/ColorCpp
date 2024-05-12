export module ColorPlus2:Hex;
import :Type;
import <string>;
import <string_view>;

namespace
{
	template<colorp2::Character CharT>
	inline constexpr char ToUpper(CharT c)
	{
		return c >= 'a' ? c - ('a' - 'A') : c;
	}
}
export namespace colorp2
{
	/// <summary>
	/// 文字コード FFFFFFFF
	/// </summary>
	struct Hex
	{
		constexpr Hex() = default;

		template<Character CharT>
		constexpr Hex(const CharT* code) :
			Hex(std::basic_string_view<CharT>(code))
		{

		}
		template<Character CharT>
		constexpr Hex(std::basic_string_view<CharT> code)
		{
			if (code.empty()) {
				return;
			}
			if (code[0] == '#') {
				code = code.substr(1);
			}
			if (code.length() == 3 || code.length() == 4) {
				for (size_t i = 0; i < 3; ++i) {
					_hex[i * 2] = _hex[i * 2 + 1] = ToUpper(code[i]);
				}
				_hex[6] = _hex[7] = (code.length() == 4) ? ToUpper(code[3]) : 'F';
			} else if (code.length() == 6 || code.length() == 8) {
				for (size_t i = 0; i < 6; ++i) {
					_hex[i] = ToUpper(code[i]);
				}
				_hex[6] = (code.length() == 8) ? ToUpper(code[6]) : 'F';
				_hex[7] = (code.length() == 8) ? ToUpper(code[7]) : 'F';
			}
		}
		std::string hex() const
		{
			return std::string(_hex, 8);
		}
		constexpr std::string_view hexView() const& noexcept
		{
			return { _hex, 8 };
		}
		std::string_view hexView() const&& noexcept = delete;

		friend constexpr bool operator==(const Hex& a, const Hex& b) = default;
	private:
		/// <summary>
		/// 文字コード (#なし)
		/// (終端文字列はなし)
		/// </summary>
		char _hex[8]{'0', '0', '0', '0' , '0', '0', 'F', 'F'};
	};
}