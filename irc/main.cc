#include "Fmt.hpp"

int	main()
{
	std::string	arr[5] = {ITAL, CYAN, YELLOW, GREEN, LOWKEY};

	int	i = -1;
	while (++i < 6)
	{
		if (i < 5)
			std::cout << arr[i];
		std::cout <<  "Hello, World! " nlreset;
	}
}

