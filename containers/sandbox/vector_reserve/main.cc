#include "iostream"
#include "vector"

#define SIZE 100

using	namespace std;

int	main ()
{
	vector<int>::size_type	z1, z2;
	vector<int>	v1, v2;
	int	i;

	i = -1;
	while (++i < SIZE)
	{
		v1.push_back(i);
		if (z1 != v1.capacity())
		{
			z1 = v1.capacity();
			cout << "capacity changed: " << z1 << endl;
		}
	}
	cout << "size at last: " << v1.size() << endl;


	cout << "\n👆 test 1 :: 👇 test 2 \n\n"; 


	i = -1;
	v2.reserve(64); // changed here
	while (++i < SIZE)
	{
		v2.push_back(i);
		if (z2 != v2.capacity())
		{
			z2 = v2.capacity();
			cout << "capacity changed: " << z2 << endl;
		}
	}
	cout << "size at last: " << v2.size() << endl;
}
