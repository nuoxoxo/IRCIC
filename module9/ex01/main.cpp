#include "iostream"
#include "RPN.hpp"

int	main(int c, char **v)
{
	if (c ^ 2)
	{
		return (0);
	}
	if (std::string(v[1]) == "test")
	{
		return (debugger(), 0);
	}
	calculator(std::string(v[1]));
}

