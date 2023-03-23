#include "iostream"
#include "Fmt.hpp"

int	main()
{
	srand(time(0));
	if (rand() % 2)
	{
		std::cout << TICK << std::endl;
		perror("funny & odd");
	}
	else
	{
		std::cout << CROSS << std::endl;
	}
}

