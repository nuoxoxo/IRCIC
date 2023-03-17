#pragma once
#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

# include "iostream"
# include "fstream"
# include "sstream"
# include "cstdlib"
# include "cstdio"
# include "map"

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

#define COLOR RED

# define TICK	GREEN " ✓" RESET
# define CROSS	_RED_ " ✘" RESET

# define PRECISION 10

template<typename T>
    std::string to_string(const T value);

std::string to_string(double const);

double	to_double_round_2(double);
double	to_double_floor_2(double);
bool	_check_params_(int, char **);
void	printerr(std::string s = "");
bool	date_is_valid(std::string &);
bool	query_is_valid(std::string &);
bool	title_is_valid(std::string &);
bool	isnumeric(std::string &);
bool	number_check(std::string &);

#endif

