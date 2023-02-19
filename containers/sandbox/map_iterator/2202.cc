#include "iostream"
#include "map"

using	namespace std;

int	main()
{
	map<string, int>::iterator	it;
	map<string, int>		D;
	string			s;

	while (!cin.eof() && getline(cin, s))
		D[s]++;
	it = D.begin();
	while (it != D.end())
	{
		cout << "\"" << it->first << "\" : " << it->second
		// << " : " << & it
		<< "\n";
		it++;
	}

	

}

