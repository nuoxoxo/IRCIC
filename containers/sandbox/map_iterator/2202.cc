#include "iostream"
#include "map"
#include "print.hpp"

using	namespace std;

int	main()
{
	map<string, int>	D;
	string			s;

	while (cin >> s)
	{
		D[s]++;
	}
	
	map_printer(D);
	map_printer(D, 1);
	map_printer(D, 3);
}
