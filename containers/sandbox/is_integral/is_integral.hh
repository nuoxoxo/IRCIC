#ifndef	IS_INTEGRAL_HH
#define	IS_INTEGRAL_HH

namespace ft
{
	template<class T, T v>
	class	integral_constant
	{
	public:
		typedef integral_constant<T, v>	type;
		typedef	T		value_type;
		static const T		value = v;

		operator T() { return v; }
	}


}
