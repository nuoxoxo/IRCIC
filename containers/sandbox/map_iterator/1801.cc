#include "iostream"
#include "map"
#include "print.tpp"

using	namespace std;

int	main()
{
	map<int, int>		D;
	int			n;

	while (cin >> n)
	{
		D[n]++;
	}
	
	print(D);
	print(D, 1);
	print(D, 3);
}
