#include "iostream"
#include "map"
#include "print.tpp"

using	namespace std;

int	main()
{
	map<string, int>	D;
	string			s;

	while (cin >> s)
	{
		D[s]++;
	}
	
	print(D);
	print(D, 1);
	print(D, 3);
}
