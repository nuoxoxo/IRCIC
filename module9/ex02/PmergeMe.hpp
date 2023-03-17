#pragma once
#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__

# include "iostream"
# include "sstream"
# include "vector"
# include "deque"
# include "algorithm" // merge
# include "sys/time.h"

# define BEFORE 0
# define AFTER 1

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

void		print_deque(std::deque<int>, bool);
void		print_vector(std::vector<int>, bool);
std::deque<int>	merge_sort(std::deque<int> &);
std::vector<int>	merge_sort(std::vector<int> &);

bool	isnumeric(std::string);
void	_usage_(std::string);

#endif

