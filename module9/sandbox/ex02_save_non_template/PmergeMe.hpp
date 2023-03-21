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
# define NOW_USING_DIY 0
# define NOW_USING_STL 1

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



void		_usage_(std::string);
bool		isnumeric(std::string);
void		print_deque(std::deque<long long>, bool);
void		print_vector(std::vector<long long>, bool);
void		merge_sort(std::vector<long long> &);
// void		merge_sort(std::deque<int> &);
void		merge_sort(std::deque<long long> &, bool);


#endif

