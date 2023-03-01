#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
#define Size 42
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>

using	namespace std;

void	pv(vi &);
void	pmii(mii &);
void	mapfill(mii &);

int	main()
{
	srand(time(0));

	vi	v(Size);
	generate(v.begin(), v.end(), []() -> int { return rand() % 100; });
	cout << "Size of vector: " << distance(v.begin(), v.end()) << endl;
	// pv(v);

	mii	m;
	mapfill(m);
	cout << "Size of map: " << distance(m.begin(), m.end()) << endl;
	pmii(m);

	/* impl. needed for unordered_map */
	/*
	mii	m;
	mapfill(m);
	cout << "Size of map: " << distance(m.begin(), m.end()) << endl;
	pmii(m);
	*/
}

void	pv(vi & v)
{
	vi::iterator it = v.begin();
	int	i = 0;
	while (it != v.end())
		i = (i%10)?i+1:1, cout << *it << ((i%10)? ' ':'\n'), ++it;
	cout << '\n';
}

void	pmii(mii & m)
{
	mii::iterator it = m.begin();
	int	i = 0;
	while (it != m.end())
		i = (i%4)?i+1:1, cout << it->first << " - " << it->second \
		    << ((i%4)? "\t\t":"\n"), ++it;
	cout << '\n';
}

void	mapfill(mii & m)
{
	int	i = -1;
	while (++i < Size)
		m[i] = rand() % 100;
}
