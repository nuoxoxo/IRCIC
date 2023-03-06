#include "iostream"
#include "random"

#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "colors.hpp"

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
	print_session_head(++i, "swap test :: vector<string>");
	{
		ft::vector<std::string>	S(42, "hello, i am a string ... theory");
		ft::vector<std::string>	T(3, "t h r e e ...");

		print_vector_head(S);
		print_vector_head(T);
		S.swap(T);
		print_vector_head(S);
		print_vector_head(T);
	}
	print_session_head(++i, "resizing :: grow & shrink");
	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(9, 31415);

		print_vector_head(A);
		print_vector_head(B);
		A.resize(10);
		B.resize(1);
		print_vector_head(A);
		print_vector_head(B);
	}
	print_session_head(++i, "reserve :: try shrinking");
	{
		ft::vector<int>		A(2, 42);
		ft::vector<int>		B(4, 31415);

		print("printing capacity", A.capacity());
		print_vector_head(A);
		print("printing capacity", B.capacity());
		print_vector_head(B);

		A.reserve(10);
		B.reserve(1);

		print("try growing capacity 2 to 10", A.capacity());
		print_vector_head(A);
		print("try shrinking from 4 to 1", B.capacity());
		print_vector_head(B);
	}
	print_session_head(++i, "testing the \".at()\" method :: vector<int>");
	{
		int	n = 12, i = -1;
		int	position;

		ft::vector<int>	vi;

		while (++i < n)
			vi.push_back(rand() % 100);

		print_vector(vi);
		position = rand() % n;
		std::cout << "[" << position << "] : " << vi[position] << nl;
		std::cout << "at(" << position << ") : " << vi.at(position) << nl;
	}
	print_session_head(++i, "testing the \".at()\" method :: vector<string>");
	{
		int	n = 10, i = -1;
		int	position, j;

		ft::vector<std::string>	vs;

		while (++i < n)
		{
			std::string	s;
			j = -1;
			while (++j < n)
			{
				char	c = rand() % 26 + 'A';
				s += c;
			}
			vs.push_back(s);
		}

		print_vector(vs);
		position = rand() % n;
		std::cout << "[" << position << "] : " << vs[position] << nl;
		std::cout << "at(" << position << ") : " << vs.at(position) << nl;
	}
	print_session_head(++i, "rbegin::++, rend::++");
	{
		ft::vector<float>	A(7, 42.42);
		ft::vector<std::string>	B(11, "B");

		A[0] = 21.21;
		A[(int)A.size() / 2] = 0.5;
		A[(int)A.size() - 1] = 99.99;

		int	i = -1;
		while (++i < (int) B.size())
			B[i][0] += i;

		print_vector(A);
		print_vector(B);

		ft::vector<float>::reverse_iterator		ra = A.rbegin();
		ft::vector<std::string>::reverse_iterator	rb = B.rbegin();

		print_vector_head(A);
		while (ra != A.rend())
			std::cout << *ra << nl, ++ra;
		std::cout << nl;

		print_vector_head(B);
		while (rb != B.rend())
			std::cout << *rb << nl, ++rb;
		std::cout << nl;
	}
	print_session_head(++i, "begin::reverse_it--, end::reverse_it--");
	{
		ft::vector<float>	A(7, 999.1);
		ft::vector<std::string>	B(9, "R");

		A[0] = 0.1;
		A[(int)A.size() / 2] = 10.55;

		int	i = -1;
		while (++i < (int) B.size())
			B[i][0] += i;

		print_vector(A);
		print_vector(B);

		ft::vector<float>::reverse_iterator		ra = A.rend();
		ft::vector<std::string>::reverse_iterator	rb = B.rend();

		print_vector_head(A);
		while (--ra != A.rbegin() - 1)
			std::cout << *ra << nl;
		std::cout << nl;

		print_vector_head(B);
		while (--rb != B.rbegin() - 1)
			std::cout << *rb << nl;
		std::cout << nl;
	}
	print_session_head(++i, "boolean operators :: size 3 vs. 2");
	{
		ft::vector<double>	A(3, 21.21);
		ft::vector<double>	B(2, 42.42);

		std::cout << std::boolalpha;
		std::cout << " < : " << (A < B) << nl; // tricky part yet nailed it
		std::cout << " > : " << (A > B) << nl;
		std::cout << " == : " << (A == B) << nl;
		std::cout << " != : " << (A != B) << nl;
		std::cout << " <= : " << (A <= B) << nl;
		std::cout << " >= : " << (A >= B) << nl2;
		std::cout << std::noboolalpha;
	}
	print_session_head(++i, "boolean operators :: same size");
	{
		ft::vector<double>	A(42, 42.42);
		ft::vector<double>	B(42, 42.42);

		std::cout << std::boolalpha;
		std::cout << " < : " << (A < B) << nl;
		std::cout << " > : " << (A > B) << nl;
		std::cout << " == : " << (A == B) << nl;
		std::cout << " != : " << (A != B) << nl;
		std::cout << " <= : " << (A <= B) << nl;
		std::cout << " >= : " << (A >= B) << nl2;
		std::cout << std::noboolalpha;
	}
	print_session_head(++i, "vector<bool>");
	{
		int	n = 12;
		ft::vector<bool> vb(n, true);

		int	position1 = rand() % n;
		int	position2 = rand() % n;

		vb[position1] = !vb[position1];
		vb[position2] = !vb[position2];

		print_vector(vb, true);

		std::cout << std::boolalpha;
		std::cout << "[" << position1 << "] : " << vb[position1] << nl;
		std::cout << "[" << position2 << "] : " << vb[position2] << nl;
		std::cout << std::noboolalpha;
	}
	print_session_head(++i, "testing :: empty()");
	{
		int	n = 12, i = -1;

		ft::vector<int>	vi;

		while (++i < n)
			vi.push_back(rand() % 100);
		while (!vi.empty())
		{
			std::cout << vi[vi.size() - 1] << nl;
			vi.pop_back();
		}
		std::cout << CYAN
		<< "// printed using while(!empty) AND pop_back() " nl2reset;
	}
}

