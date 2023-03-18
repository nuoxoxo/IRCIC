#include "iostream"

#include "RPN.hpp"

// drive

int	main(int c, char **v)
{
	std::string	line;

	if (c != 2)
	{
		return (0);
	}
	line = v[1];
	if (line == "test")
	{
		default_debugger();
	}
	else
	{
		RPN(line, "", true);
	}
}


