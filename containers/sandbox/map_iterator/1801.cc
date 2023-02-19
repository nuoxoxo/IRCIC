#include "iostream"
#include "map"
#include "print.hpp"

using	namespace std;

int	main()
{
	map<int, int>	D;
	int		n;

	while (cin >> n)
	{
		D[n]++;
	}
	
	map_printer(D);
	map_printer(D, 1);
	map_printer(D, 3);
}
