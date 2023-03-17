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

template<typename T>
    std::string to_string(const T value);

std::string to_string(float const);

float	to_float_round_2(float);
float	to_float_floor_2(float);
bool	_check_params_(int, char **);
void	printerr(std::string s = "");
bool	date_is_valid(std::string &);
bool	query_is_valid(std::string &);
bool	title_is_valid(std::string &);
bool	isnumeric(std::string &);
bool	number_check(std::string &);

#endif

