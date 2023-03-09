#include "iostream"

#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp" // <---
#include "colors.hpp"

#include "cstdlib" // random
#include "vector" // for mazoise reproduced

int	main()
{
	int	i = 0;

	srand(time(0));

	print_session_head(++i, "swap test :: vector<int>");

	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(9, 196883);
		// ft::vector<std::string>	b(9, "hello, 196883");
		/// ! swap applies only when 2 vectors are of the same type

		print_vector_head(A);
		print_vector_head(B);
		A.swap(B);
		print_vector_head(A);
		print_vector_head(B);
	}

}
