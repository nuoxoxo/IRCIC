#pragma once
#ifndef __COLORS_HPP__
# define __COLORS_HPP__

# define nl "\n"
# define nl2 "\n\n"
# define nlreset " \n" RESET
# define nl2reset " \n\n" RESET
# define LOWKEY "\033[0;2m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define MAG "\033[0;35m"
# define ITAL "\033[3m"
# define RESET "\033[0;0m"

# define TICK	GREEN" ✓"RESET
# define CROSS	RED" ✘"RESET
// helper


template<typename T>
void	printer_vector(T & v)
{
	int	i = -1;
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	while (++i < (int) v.size()) std::cout << v[i] << nl;
	std::cout << nl2reset;
}

template<typename T>
void	printer_vector_head(T & v)
{
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << v[0] << nl2;
}

void	print_session_head(int & i, const std::string & message)
{
	std::cout << nl << i << " :: " YELLOW << message << nl2reset;
}

#endif
