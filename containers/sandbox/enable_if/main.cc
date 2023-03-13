
#include "iostream"
#include "type_traits"
#include "Fmt.hpp"

// enable_if example: 2 ways of using enable_if

template < class T >
typename std::enable_if< std::is_integral<T>::value, bool >::type
is_odd(T);

template < class T, 
class = typename std::enable_if<std::is_integral<T>::value>::type >
bool is_even (T);

int	main()
{
	{
		short int	n; // code does not compile if type of i is not integral

		std::cout << std::boolalpha;

		n = -1;
		while (++n < 5)
		{
			std::cout << "number " c2 << n << R << " is odd: "
			<< is_odd(n) << nl;

			std::cout << "number " c2 << n << R << " is even: "
			<< is_even(n) << nl2;
		}
	}
	{
		// float	f = 2.0f; // no matching func bcz not enabled
		long long	f = 2147483647;
		int		i = -1;

		while (++i < 2)
		{
			std::cout << "number " c1 << f << R << " is odd: "
			<< is_odd(f) << nl;

			std::cout << "number " c1 << f << R << " is even: "
			<< is_even(f) << nl2;

			f++;
		}

	}


	return 0;
}


//	helper

// way 1 - the return type (bool) is only valid if T is an integral type:

template < class T >
typename
std::enable_if< std::is_integral<T>::value, bool >::type is_odd(T num)
{
	return (bool) (num % 2);
}

// way 2 - the second template argument is only valid if T is an integral type:

// template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
template < class T, class type >
bool	is_even (T num)	// ( c++11 required )
{
	return ( !(bool) (num % 2));
}


