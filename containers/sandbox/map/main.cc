#include "iostream"

// #include "stack.hpp"
// #include "vector.hpp"
#include "colors.hpp"
#include "pair.hpp"
#include "map.hpp" // <---

#include "map"

#include "cstdlib" // random
#include "vector" // for reproducing mazoise

#define MCR ft

int	main()
{
	int	i = 0;

	srand(time(0));

	{
		MCR::map<int, int>	E;
		MCR::map<int, int>::iterator	it;

		print_session_head(++i, " map iterator ");
		{
			int i = 0;
			while (++i < 12)
			{
				E[i + 1] = rand() % 42;
			}
			it = E.begin();
			while (it != E.end())
			{
				std::cout << it->first << " : " << it->second << nl;
				++it;
			}
			std::cout << nl;
		}
		print_session_head(++i, " map.count ");
		{
			int	to_find = 12;
			std::cout << CYAN "try to find a key: " << to_find << nlreset;
			std::cout << "result: " << E.count(to_find) << nl2;

			to_find = 13;
			std::cout << CYAN "try to find a key: " << to_find << nlreset;
			std::cout << "result: " << E.count(to_find) << nl2;
		}
		print_session_head(++i, " map.*_bound ");
		{
			int	b = 10;
			std::cout << CYAN "try bound of: " << b << nlreset;
			std::cout << "upper bound: " << (E.upper_bound(b))->second << nl;
			std::cout << "lower bound: " << (E.lower_bound(b))->second << nl;
		}
	}
	std::cout << std::endl;

}
