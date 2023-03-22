#pragma once
#ifndef __FMT_HPP__
# define __FMT_HPP__

# include "iostream"
# include "sstream"
# include "vector"
# include "deque"
# include "map"
# include "algorithm" // merge
# include "sys/time.h"


# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define YELLOW "\033[0;33m"
# define MAG "\033[0;35m"
# define RED "\033[0;31m"
# define ITAL "\033[3m"
# define LOWKEY "\033[0;2m"
# define RESET "\033[0;0m"

# define TICK	GREEN " ✓" RESET
# define CROSS	RED " ✘" RESET

# define POINT_R " 👉 "
# define POINT_L " 👈 "

# define nl "\n"
# define nl2 "\n\n"
# define nlreset " \n" RESET
# define nl2reset " \n\n" RESET

bool	argv_is_invalid(char *v)
{
	int	i;

	if (strlen(v) ^ 4)
	{
		return (true);
	}
	i = -1;
	while (v[++i])
	{
		if (isdigit(v[i]))
			continue ;
		return (true);
	}
	return (false);
}

void	_usage_()
{
	std::cout << "Usage: \n$> ./ircserv  _port_  _pass_ " nl;
}


#endif

// 


