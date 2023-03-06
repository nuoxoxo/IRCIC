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

// impl. restricted to >= c++std-11
/*
void	print() { std::cout << nl2reset; }
template<typename T, typename... Types>
void	print(T n1, Types... n2)
{
	std::cout << n1 << nl ;
	print(n2...);
}
*/

template<typename T>
void	print(const T & item) { std::cout << CYAN << item << nl2reset; }

template<typename T>
void	print(const std::string & w, const T & item)
{ std::cout << CYAN << w << ": " GREEN << item << nlreset; }

template<typename T>
void	print_vector(T & v)
{
	int	i = -1;
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << "(cpct : " << GREEN << v.capacity() << RESET << ") \n";
	while (++i < (int) v.size()) std::cout << v[i] << nl;
	std::cout << nl2reset;
}

template<typename T>
void	print_vector_head(T & v)
{
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << "(cpct : " << GREEN << v.capacity() << RESET << ") \n";
	std::cout << YELLOW << "head : " << v[0] << nl2reset;
}

void	print_session_head(int & i, const std::string & message)
{
	std::cout << nl << i << " :: " YELLOW << message << nl2reset;
}

#endif
