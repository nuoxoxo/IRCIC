#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# define nl "\n"
# define nl2 "\n\n"
# define nlreset " \n" RESET
# define nl2reset " \n\n" RESET
# define LOWKEY "\033[0;2m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define MAG "\033[0;35m"
# define RED "\033[0;31m"
# define RESET "\033[0;0m"
# define ITAL "\033[3m"

# define TICK	GREEN " ✓" RESET
# define CROSS	_RED_ " ✘" RESET

bool	isnumeric(std::string s)
{
	size_t	i = -1;
	while (++i < s.length())
	{
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
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


#endif


