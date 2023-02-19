#include "iostream"
#include "map"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0;0m"

using	namespace std;

void	map_printer(map<int, int>& D, int n = 0)
{
	map<int, int>::iterator	it;

	it = D.begin();
	if (n == 1)
	{
		it++;
	}
	else if (n)
	{
		cout << RED "error: adding " << n
		<< " to bidirectional iterator. \n\n" << RESET;
		return ;
	}
	while (it != D.end())
	{
		cout << it->first << " : " << it->second
		<< " : " << & it
		<< "\n";
		it++;
	}
	cout << YELLOW "\n------------ end. ------------ \n\n" RESET;
}

void	map_printer(map<string, int>& D, int n = 0)
{
	map<string, int>::iterator	it;

	it = D.begin();
	if (n == 1)
	{
		it++;
	}
	else if (n)
	{
		cout << RED "error: adding " << n
		<< " to bidirectional iterator. \n\n" << RESET;
		return ;
	}
	while (it != D.end())
	{
		cout << it->first << " : " << it->second
		<< " : " << & it
		<< "\n";
		it++;
	}
	cout << YELLOW "\n------------ end. ------------ \n\n" RESET;
}


