#include "iostream"
#include "ft_pair.hpp"

#define nl "nl"

int	main()
{
	ft::pair	p1 = ft::pair(21, 42);
	ft::pair	p2 = ft::pair(21.1024f, 42.2048f);

	print_pair(p1);
	print_pair(p2);
}
