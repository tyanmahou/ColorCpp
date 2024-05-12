export module ColorPlus2:ColorCastTrait;

export namespace colorp2
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

	template<class To, class From>
	inline constexpr To ColorCast(const From& from)
	{
		return ColorCastTraits<To, From>::Cast(from);
	}
}