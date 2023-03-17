#include "iostream"
#include "map"

using	namespace std;

int	main()
{
	map<char, int> dict;

	dict['a'] = 20;
	dict['b'] = 40;
	dict['d'] = 60;
	dict['e'] = 80;
	dict['g'] = 100;

	map<char, int>::iterator c_lower = dict.lower_bound ('c');
	map<char, int>::iterator d_lower = dict.lower_bound ('d');
	map<char, int>::iterator f_upper = dict.upper_bound ('f');
	map<char, int>::iterator one_upper = dict.upper_bound ('1');

	cout << "c " << c_lower->first << endl;
	cout << "d " << d_lower->first << endl;
	cout << "f " << f_upper->first << endl;
	cout << "1 " << one_upper->first << endl;
}
