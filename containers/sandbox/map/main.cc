#include "iostream"

// #include "stack.hpp"
// #include "vector.hpp"
#include "colors.hpp"
#include "pair.hpp"
#include "map.hpp" // <---

#include "cstdlib" // random
#include "vector" // for reproducing mazoise

int	main()
{
	int	i = 0;

	srand(time(0));

	print_session_head(++i, " map test ");

	{
		ft::map<int, int>	E;
		ft::map<int, int>::iterator	it;

		int i = 0;
		while (++i < 12)
		{
			E[i + 1] = rand() % 99;
		}
		it = E.begin();
		while (it != E.end())
		{
			std::cout << it->first << " : " << it->second << nl;
			++it;
		}
	}

}
