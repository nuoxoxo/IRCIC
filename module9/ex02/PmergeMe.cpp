#include "PmergeMe.hpp"

// using deque # 1 : library merge-insert
// xD

void	merge_sort(std::deque<int> & D, bool using_stl)
{

	if ( !using_stl)
		return ;
	if (D.size() < 1)
		return ;

	int			mid = D.size() / 2;
	std::deque<int>		L (D.begin(), D.begin() + mid);
	std::deque<int>		R (D.begin() + mid, D.end());
	std::deque<int>		temp;

	sort(L.begin(), L.end());
	sort(R.begin(), R.end());
	merge(L.begin(), L.end(), R.begin(), R.end(),
	 std::back_inserter<std::deque<int> >(temp));
	D = temp;
}


// using deque # 2 : generic
// :D

void	merge_sort(std::deque<int> & D)
{
	std::deque<int>	L, R;
	int	i, mid, size;

	// split
	if (D.size() < 2)
		return ;
	size = (int) D.size();
	mid = size / 2;
	i = -1;
	while (++i < mid)
	{
		L.push_back(D.back());
		D.pop_back();
	}
	i = -1;
	while (++i < size - mid)
	{
		R.push_back(D.back());
		D.pop_back();
	}

	// recurse
	merge_sort(L);
	merge_sort(R);

	// insert while comparing
	while (!L.empty() && !R.empty())
	{
		if (L.front() < R.front())
		{
			D.push_back(L.front());
			L.pop_front();
		}
		else
		{
			D.push_back(R.front());
			R.pop_front();
		}
	}

	// get the rest
	while (!L.empty())
	{
		D.push_back(L.front());
		L.pop_front();
	}
	while (!R.empty())
	{
		D.push_back(R.front());
		R.pop_front();
	}
}


void	merge_sort(std::vector<int>& a)
{
	if (a.size() > 1)
	{
		int	mid = a.size() / 2;
		int	i, j, k;

		std::vector<int>	L(a.begin(), a.begin() + mid);
		std::vector<int>	R(a.begin() + mid, a.end());

		merge_sort(L);
		merge_sort(R);
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
