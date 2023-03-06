#include "iostream"
#include "colors.hpp"
#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"

int	main()
{
	int	i = 0;

	print_session_head(++i, "swap test :: vector<int>");
	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(9, 196883);
		// ft::vector<std::string>	b(9, "hello, 196883");
		/// ! swap applies only when 2 vectors are of the same type

		printer_vector_head(A);
		printer_vector_head(B);
		A.swap(B);
		printer_vector_head(A);
		printer_vector_head(B);
	}
	print_session_head(++i, "swap test :: vector<string>");
	{
		ft::vector<std::string>	S(42, "hello, i am a string ... theory");
		ft::vector<std::string>	T(3, "t h r e e ...");

		printer_vector_head(S);
		printer_vector_head(T);
		S.swap(T);
		printer_vector_head(S);
		printer_vector_head(T);
	}
	print_session_head(++i, "resizing :: grow & shrink");
	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(9, 31415);

		printer_vector_head(A);
		printer_vector_head(B);
		A.resize(10);
		B.resize(1);
		printer_vector_head(A);
		printer_vector_head(B);
	}
	print_session_head(++i, "reserve :: try shrinking");
	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(4, 31415);

		print("printing capacity", A.capacity());
		printer_vector_head(A);
		print("printing capacity", B.capacity());
		printer_vector_head(B);

		A.reserve(10);
		B.reserve(1);

		print("try growing capacity 2 to 10", A.capacity());
		printer_vector_head(A);
		print("try shrinking from 4 to 1", B.capacity());
		printer_vector_head(B);
	}
}

