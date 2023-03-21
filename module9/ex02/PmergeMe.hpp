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
# define USE_DIY 0
# define USE_STL 1

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


bool		isnumeric(std::string);
void		_usage_(std::string);


template<typename T>
void	Cmon_Lets_Use_STL_Oh_YEAH( T & D)
{
	int	mid = D.size() / 2;
	T	L (D.begin(), D.begin() + mid);
	T	R (D.begin() + mid, D.end());
	T	temp;

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	merge(L.begin(), L.end(), R.begin(), R.end(),
	 std::back_inserter<T>(temp));
	D = temp;
}


template<typename T> // T is either a deque or a vector
void	merge_sort(T & a, bool Use_STL)
{
	if (a.size() < 1)
		return ;

	// Route : STL

	if (Use_STL)
	{
		Cmon_Lets_Use_STL_Oh_YEAH( a );
		return ;
	}

	// Route : Generic

	if (a.size() > 1)
	{
		int	mid = a.size() / 2;
		int	i, j, k;

		T	L(a.begin(), a.begin() + mid);
		T	R(a.begin() + mid, a.end());

		merge_sort(L, ! Use_STL);
		merge_sort(R, ! Use_STL);
		i = j = k = 0;
		while (i < (int) L.size() && j < (int) R.size())
		{
			if (L[i] < R[j])
			{
				a[k] = L[i];
				++i;
			}
			else
			{
				a[k] = R[j];
				++j;
			}
			++k;
		}
		while (i < (int) L.size())
		{
			a[k] = L[i];
			++i;
			++k;
		}
		while (j < (int) R.size())
		{
			a[k] = R[j];
			++j;
			++k;
		}
	}
}


template<typename T>
void	print_container(T & a, bool option)
{
	int	i;

	if (option == BEFORE)
		std::cout << "Before:\t" YELLOW;
	if (option == AFTER)
		std::cout << "After: \t" GREEN;
	if (a.size() < 11)
	{
		i = -1;
		while (++i < (int) a.size())
			std::cout << a[i] << ' ';
	}
	else
	{
		i = -1;
		while (++i < 4)
			std::cout << a[i] << ' ';
		std::cout << RESET "[...]";
	}
	std::cout << nlreset;
}


#endif
