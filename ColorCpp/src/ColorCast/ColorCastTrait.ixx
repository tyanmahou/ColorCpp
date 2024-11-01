export module ColorCpp:ColorCastTrait;
export import :ColorCastDependency;

export namespace colorcpp
{
    template<class To, class From>
    struct ColorCastTraits;

    template<class To, class From>
    [[nodiscard]] inline constexpr To ColorCast(const From& from)
    {
        return ColorCastTraits<To, From>::Cast(from);
    }

    template<class To, class From>
    struct ColorCastTraits
    {
        [[nodiscard]] static constexpr To Cast(const From& from)
        {
            if constexpr (DependOn<From, To>) {
                using from_depend_type = typename ColorCastDependency<From>::depend_type;
                return ColorCast<To>(ColorCast<from_depend_type>(from));
            } else {
                using to_depend_type = typename ColorCastDependency<To>::depend_type;
                return ColorCast<To>(ColorCast<to_depend_type>(from));
            }
        }
    };
    template<class T>
    struct ColorCastTraits<T, T>
    {
        [[nodiscard]] static constexpr T Cast(const T& from)
        {
            return from;
        }
    };
}
