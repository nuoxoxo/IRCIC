#include "iostream"
#include "vector"

#define nl "\n"

using	namespace std;

int	main ()
{
	vector<int>	A, B, C;
	int		arr[] = { 21, 42, 196883, 22, 43, 1024 };

	A.assign(7, 42); // size: 7

	B.assign(A.begin() + 1, A.end() - 1); // size: 5

	C.assign(arr, arr + 3); // 3

	cout << "Size of A: " << A.size() << nl;
	cout << "Size of B: " << B.size() << nl;
	cout << "Size of C: " << C.size() << nl;
}
