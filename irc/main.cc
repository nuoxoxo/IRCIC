#include "Fmt.hpp"

int	main(int c, char **v)
{
	if (c ^ 2)
		return (_usage_(), 0 /* 1 */);

	std::string	arr[5] = {ITAL, CYAN, YELLOW, GREEN, LOWKEY};

	int	i = -1;
	while (++i < 6)
	{
		if (i < 5)
			std::cout << arr[i];
		std::cout <<  "Hello, World! " nlreset;
	}

	(void) v;

}

