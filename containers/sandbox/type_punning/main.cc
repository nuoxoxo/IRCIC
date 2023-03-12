#include "iostream"
#include "../Fmt.hpp"

static int i = 0;

int	main()
{
	std::cout << CYAN "double \n" RESET;
	{
		int	i = 42;
		double	d = (double) i;

		std::cout << i << ", size(): " << sizeof(i) << std::endl;
		std::cout << d << ", size(): " << sizeof(d) << std::endl;
	}
	std::cout << CYAN " \ncasting with double \n" RESET;
	{
		int	i = 42;
		double	d = (double) i;

		std::cout << i << ", size(): " << sizeof(i) << std::endl;
		std::cout << d << ", size(): " << sizeof(d) << std::endl;
	}
	std::cout << CYAN " \ndouble pointer type punning \n" RESET;
	{
		int	i = 42;
		double	d = *(double *)& i;

		std::cout << i << ", size(): " << sizeof(i) << std::endl;
		std::cout << d << ", size(): " << sizeof(d) << std::endl;
	}
}


