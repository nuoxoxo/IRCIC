#include "iostream"

using	namespace std;

class	X {};
struct	Y { using type = X; };

template<class T>
void	print(T)
{
	cout << __FUNCTION__ << " - func(T)" << endl;
}

template<class T>
void	print(typename T::type)
{
	cout << __FUNCTION__ << " - func(T::type)" << endl;
}

int	main()
{
	print<X>(X{});
	print<Y>(X{});
}
