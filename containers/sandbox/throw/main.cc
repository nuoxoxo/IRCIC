#include "iostream"
#include "stdexcept"

using	namespace std;

int	add2positive(int, int);

int	main()
{
	try
	{
		cout << add2positive(-21, 42); //exception
	}
	catch (std::invalid_argument & e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	return 0;
}

int	add2positive(int l, int r)
{
	if (l < 0 || r < 0)
		throw std::invalid_argument("positive arguments needed");
	return (l + r);
}
