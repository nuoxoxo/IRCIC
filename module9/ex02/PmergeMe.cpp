#include "PmergeMe.hpp"

bool	isnumeric(std::string s)
{
	size_t		i;

	if (s == "")
		return (false);
	i = -1;
	while (++i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	return (true);
}

void	_usage_(std::string message)
{
	if (message == "Error")
	{
		std::cout << message << nlreset;
		return ;
	}
	if (message != "")
		std::cout << YELLOW << message << nlreset;
	std::cout << "Example: \n";
	std::cout << "$> ./PmergeMe 3 5 9 7 4" nl;
}
