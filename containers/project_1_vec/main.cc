#include "iostream"

#include "colors.hpp"
#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"

#define STD 0
#define FT 1

int	main()
{
	{
		ft::vector<int>		a(2, 42);
		ft::vector<int>		b(9, 196883);
		// ft::vector<std::string>	b(9, "hello, 196883");
		/// ! swap applies only when 2 vectors are of the same type

		printer_vector_head(a);
		printer_vector_head(b);
		a.swap(b);
		printer_vector_head(a);
		printer_vector_head(b);
	}
}

