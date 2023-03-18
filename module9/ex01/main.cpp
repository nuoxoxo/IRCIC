#include "iostream"
#include "RPN.hpp"

// drive

int	main(int c, char **v)
{
	if (c != 2)
	{
		return (0);
	}
	if (std::string(v[1]) == "test")
	{
		return (default_debugger(), 0);
	}
	calc(std::string(v[1]));
}

