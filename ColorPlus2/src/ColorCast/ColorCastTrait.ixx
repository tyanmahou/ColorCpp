export module ColorPlus2:ColorCastTrait;
export import :ColorCastDependency;

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

	template<class To, class From> requires DependOn<From, To>
	struct ColorCastTraits<To, From>
	{
		using from_depend_type = typename ColorCastDependency<From>::depend_type;
		static constexpr To Cast(const From& from)
		{
			return ColorCast<To>(ColorCast<from_depend_type>(from));
		}
	};
	template<class To, class From> requires (!DependOn<From, To>)
	struct ColorCastTraits<To, From>
	{
		using to_depend_type = typename ColorCastDependency<To>::depend_type;
		static constexpr To Cast(const From& from)
		{
			return ColorCast<To>(ColorCast<to_depend_type>(from));
		}
	};
}