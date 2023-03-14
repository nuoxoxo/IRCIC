#include "iostream"
#include "map"
#include "Fmt.hpp"

using	namespace std;

void	header(int, string);

int	main()
{
	int	i = -1;

	header(++i, "const iter on map<int, int>");
	{
		map<int, int>::const_iterator	it;
		// map<int, int>::iterator	it;
		map<int, int>	E;
		int	i = 0;

		E[10] = 1024;
		E[21] = 42;
		E[32] = 43;
		E[99] = 100;
		E[999] = 1000;

		it = E.begin();
		while (it != E.end())
		{
			it->second++;
			cout << YELLOW "pair " << ++i << RESET << ": "
			<< it->first << " - " << it->second << nl;
			++it;
		}
	}
	header(++i, "normal iter on map<const int, const int>");
	/*{
		map<int, int>::const_iterator	it;
		map<int, int>	E;
		int	i = 0;

		E[10] = 1024;
		E[21] = 42;
		E[32] = 43;
		E[99] = 100;
		E[999] = 1000;

		it = E.begin();
		while (it != E.end())
		{
			cout << YELLOW "pair " << ++i << RESET << ": "
			<< it->first << " - " << it->second << nl;
			++it;


		}
	}*/
}

void	header(int i, string msg)
{
	cout << GREEN nl "test " << i << RESET " :: " YELLOW << msg << nl2;
}
