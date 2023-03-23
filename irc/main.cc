#include "Fmt.hpp"

int	main(int c, char **v)
{
	if (c ^ 3 || argv_is_invalid(v[1]) || argv_is_invalid(v[2]))
	{
		return (_usage_(), 0 /*1*/);
	}

	std::string	arr[5] = {ITAL, CYAN, YELLOW, GREEN, LOWKEY};
	int		i = -1;

	while (++i < 6)
	{
		std::cout << ( i < 5 ? arr[i] : "" ) << "Hello, World! " nlreset;
	}

	// Start server here

	(void) v;


}

