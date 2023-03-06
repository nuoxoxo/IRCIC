#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace	ft
{
	template<class T, T val>
	struct	integral_constant
	{
		static const T					value = val;
		typedef T						value_type;
		typedef integral_constant<T, val>	type;
		operator T() { return val; }
	};

	// true and false type implementation
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	// Default type = false
	template<class T>
	struct is_integral : public false_type
	{};

	template<>
	struct is_integral<bool> : public true_type {};

	template<>
	struct is_integral<char> : public true_type {};

	template<>
	struct is_integral<wchar_t> : public true_type {};

	template<>
	struct is_integral<signed char> : public true_type {};

	template<>
	struct is_integral<short int> : public true_type {};

	template<>
	struct is_integral<int> : public true_type {};

	template<>
	struct is_integral<long int> : public true_type {};

	template<>
	struct is_integral<unsigned char> : public true_type {};

	template<>
	struct is_integral<unsigned short int> : public true_type {};

	template<>
	struct is_integral<unsigned int> : public true_type {};

	template<>
	struct is_integral<unsigned long int> : public true_type {};

	// template<>
	// struct is_integral<long long int> : public true_type {};
	/// 
	/// C++98 doesnt support long long with -pedantic

	// template<>
	// struct is_integral<unsigned long long int> : public true_type {};
	/// 
	/// C++98 doesnt support long long with -pedantic
}

#endif
