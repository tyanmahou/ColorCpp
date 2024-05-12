export module ColorPlus2:Hex;
import <string_view>;

export namespace cp2
{
	/// <summary>
	/// 文字コード FFFFFFFF
	/// </summary>
	struct Hex
	{
		constexpr Hex() = default;

		template<class CharT>
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
					_hex[i] = _hex[i * 2 + 1] = code[i];
				}
				_hex[6] = _hex[7] = (code.length() == 4) ? code[3] : 'F';
			} else if (code.length() == 6 || code.length() == 8) {
				for (size_t i = 0; i < 6; ++i) {
					_hex[i] = code[i];
				}
				_hex[6] = (code.length() == 8) ? code[6] : 'F';
				_hex[7] = (code.length() == 8) ? code[7] : 'F';
			}
		}

		constexpr std::string_view hex() const noexcept
		{
			return { _hex, 8 };
		}

		friend constexpr bool operator==(const Hex& a, const Hex& b) = default;
	private:
		/// <summary>
		/// 文字コード (#なし)
		/// (終端文字列はなし)
		/// </summary>
		char _hex[8]{'0', '0', '0', '0' , '0', '0', 'F', 'F'};
	};
}