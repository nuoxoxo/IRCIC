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
# define RED "\033[0;31m"
# define RESET "\033[0;0m"
# define ITAL "\033[3m"

# define TICK	GREEN " ✓" RESET
# define CROSS	RED " ✘" RESET


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


// print

template<typename T>
void	print(const T & item) { std::cout << CYAN << item << nl2reset; }

template<typename T>
void	print(const std::string & w, const T & item)
{ std::cout << CYAN << w << ": " GREEN << item << nlreset; }


// print vector<T>

template<typename T>
void	print_vector(T & v)
{
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << "(cpct : " << GREEN << v.capacity() << RESET << ") \n";

	if (v.empty())
	{
		std::cout << CYAN "(empty vector)" nl2reset;
		return ;
	}

	int	i = -1;

	std::cout << CYAN << "(printer starts)" << RESET << " \n";
	while (++i < (int) v.size()) std::cout << i << " : " << v[i] << nl;
	std::cout << CYAN << "(printer ends)" << RESET nl2reset;
}

template<typename T>
void	print_vector(T & v, bool is_vector_int)
{
	int	i = -1;

	if (is_vector_int)
		std::cout << std::boolalpha;
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << "(cpct : " << GREEN << v.capacity() << RESET << ") \n";
	std::cout << CYAN << "(printer starts)" << RESET << " \n";
	while (++i < (int)v.size())
	{
		std::cout << i << " : ";
		if (!v[i])
			std::cout << MAG;
		std::cout << v[i] << nlreset;
	}
	std::cout << CYAN << "(printer ends)" << RESET nl2reset;
	std::cout << std::noboolalpha;
}

// print vector head

template<typename T>
void	print_vector_head(T & v)
{
	std::cout << "(size : " << GREEN << v.size() << RESET << ") \n";
	std::cout << "(cpct : " << GREEN << v.capacity() << RESET << ") \n";
	if (v.size())
		std::cout << CYAN << "head : " << v.front() << nl2reset;
	else
		std::cout << CYAN << "head : " << "(None)" << nl2reset;
}

void	print_session_head(int & i, const std::string & message)
{
	std::cout << nl << "No. " << i << " :: " YELLOW << message << nl2reset;
}

#endif
