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

void	print_deque(std::deque<int> a, bool option)
{
	std::deque<int>::iterator	it;

	if (option == BEFORE)
		std::cout << "Before:\t" YELLOW;
	if (option == AFTER)
		std::cout << "After: \t" GREEN;
	if (a.size() < 11)
	{
		it = a.begin();
		while (it != a.end())
		{
			std::cout << *it << ' ';
			it++;
		}
	}
	else
	{
		it = a.begin();
		while (it != a.begin() + 4)
		{
			std::cout << *it << ' ';
			it++;
		}
		std::cout << "[...]";
	}
	std::cout << nlreset;
	/*
	if (option == AFTER)
	{
		std::cout << "Time to process a range of\t"
		<< CYAN << a.size() << RESET
		<< " elements with std::deuqe :\t";// << print time //TODO
	}
	*/
}


void	print_vector(std::vector<int> a, bool option)
{
	if (option == BEFORE)
		std::cout << "Before:\t" YELLOW;
	if (option == AFTER)
		std::cout << "After: \t" GREEN;
	if (a.size() < 11)
	{
		int	i = -1;
		while (++i < (int) a.size())
			std::cout << a[i] << ' ';
	}
	else
	{
		int	i = -1;
		while (++i < 4)
			std::cout << a[i] << ' ';
		std::cout << "[...]";
	}
	std::cout << nlreset;
	/*
	if (option == AFTER)
	{
		std::cout << "Time to process a range of\t"
		<< CYAN << a.size() << RESET
		<< " elements with std::vector :\t";// << print time //TODO
	}
	*/
}

std::deque<int>	merge_sort(std::deque<int> & a)
{
	std::deque<int>	res;

	if (a.size() > 1)
	{
		int		mid = a.size() / 2;
		std::deque<int>	d1(a.begin(), a.begin() + mid);
		std::deque<int>	d2(a.begin() + mid, a.end());

		sort(d1.begin(), d1.end());
		sort(d2.begin(), d2.end());
		merge(d1.begin(), d1.end(), d2.begin(), d2.end(),
			std::back_inserter<std::deque<int> >(res));
	}
	else
	{
		res = a;
	}

	return (res);
}

std::vector<int>	merge_sort(std::vector<int>& a)
{
	if (a.size() > 1)
	{
		int	mid = a.size() / 2;
		int	i, j, k;

		std::vector<int>	L(a.begin(), a.begin() + mid);
		std::vector<int>	R(a.begin() + mid, a.end());

		L = merge_sort(L);
		R = merge_sort(R);
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
	return (a);
}


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


