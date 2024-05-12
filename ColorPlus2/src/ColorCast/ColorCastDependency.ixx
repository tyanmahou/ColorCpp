export module ColorPlus2:ColorCastDependency;
import <type_traits>;
import <concepts>;

export namespace colorp2
{
	template<class T>
	struct ColorCastDependency
	{
		using depend_type = void;
	};

	template<class T, class U>
	struct IsDependOn : IsDependOn<typename ColorCastDependency<T>::depend_type, U>
	{
	};
	template<class T>
	struct IsDependOn<T, T> : std::true_type
	{
	};
	template<class T>
	struct IsDependOn<void, T> : std::false_type
	{
	};

	template<class T, class U>
	concept DependOn = IsDependOn<T, U>::value;
}