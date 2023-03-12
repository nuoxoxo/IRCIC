#include "iostream"
#include "Fmt.hpp"

using	namespace std;

int	negate(int i) { return -i; }

template<typename T>
typename T::value_type	negate(const T & t) { return ( -T(t) ); }
// this func should be invalid, since int has no member named value_type

int	main()
{
	negate(42);
}

