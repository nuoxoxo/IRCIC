#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
#include "unordered_map"

#define Size 42
#define vi vector<int>
#define mii map<int, int>
#define umii unordered_map<int, int>

using	namespace std;

void	pv(vi &);
void	pmii(mii &);
void	pmii(umii &); // ovld

template<class T>
void	mapfill(T &);

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

	umii	u;
	mapfill(u);
	cout << "Size of map: " << distance(u.begin(), u.end()) << endl;
	pmii(u);
}

void	pv(vi & v) // 
{
	vi::iterator it = v.begin();
	int	i = 0;

	while (it != v.end())
		i = (i%10)?i+1:1, cout << *it << ((i%10)? ' ':'\n'), ++it;
	cout << "\n\n";
}

void	pmii(mii & m) // printer for map<int,int>
{
	mii::iterator it = m.begin();
	int	i = 0;

	while (it != m.end())
		i = (i % 4) ? i + 1 : 1, \
		cout << it->first << " - " << it->second \
		<< ((i % 4) ? "\t\t" : "\n"), ++it;
	cout << "\n\n";
}

void	pmii(umii & u) // printer for unordered_map<int,int>
{
	umii::iterator it = u.begin();
	int	i = 0;

	while (it != u.end())
		i = (i % 4) ? i + 1 : 1, \
		cout << it->first << " - " << it->second \
		<< ((i % 4) ? "\t\t" : "\n"), ++it;
	cout << "\n";
}

template<class T>
void	mapfill(T & m)
{
	int	i = -1;

	while (++i < Size)
		m[i] = rand() % 100;
}
