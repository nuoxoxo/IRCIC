#include "iostream"
#include "sstream"
#include "vector"
#include "PmergeMe.hpp"

#define BEFORE 0
#define AFTER 1

using	namespace std;

void		print_vector(vector<int>, bool);
vector<int>	merge_sort(vector<int>&);

int	main(int c, char *v[])
{
	vector<int>	a;
	int		i;
	int		n;

	if (c < 2)
		return (_usage_("no number given. exit now."), 1);
	i = 0;
	while (++i < c)
	{
		if ( ! isnumeric(v[i]))
			return (_usage_("Error"), 1);
		stringstream(v[i]) >> n;	
		a.push_back(n);
	}
	print_vector(a, BEFORE);
	merge_sort(a);
	print_vector(a, AFTER);
}

void	print_vector(vector<int> a, bool option)
{
	if (option == BEFORE)
		cout << "Before:\t" YELLOW;
	if (option == AFTER)
		cout << "After: \t" GREEN;
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
		cout << "[...]";
	}
	cout << nlreset;
	if (option == AFTER)
	{
		cout << "Time to process a range of\t"
		<< CYAN << a.size() << RESET
		<< " elements with std::vector :\t";// << print time //TODO
	}
}

vector<int>	merge_sort(vector<int>& a)
{
	if (a.size() > 1)
	{
		int	mid = a.size() / 2;
		int	i, j, k;

		vector<int>	L(a.begin(), a.begin() + mid);
		vector<int>	R(a.begin() + mid, a.end());

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

