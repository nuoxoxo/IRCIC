#include "iostream"
// #include "random"

#include "pair.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "colors.hpp"

#include "cstdlib"

# include "vector" // for reproducing mazoise

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
		int			n = 12;
		ft::vector<bool>	B(n, true);

		int	position1 = rand() % n;
		int	position2 = rand() % n;

		B[position1] = !B[position1];
		B[position2] = !B[position2];

		print_vector(B, true);

		std::cout << std::boolalpha;
		std::cout << "[" << position1 << "] : " << B[position1] << nl;
		std::cout << "[" << position2 << "] : " << B[position2] << nl;
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
		std::cout
		<< CYAN "# while(!empty) print, pop_back() " nl2reset;
	}

	print_session_head(++i, "testing :: erase()");

	{
		std::string	msg = "erase::vi.begin(), vi.begin() + ";
		int		n = 12, i = -1, offset;

		ft::vector<int>	vi;

		while (++i < n)
			vi.push_back(rand() % 100);

		print_vector(vi);
		offset = 3;
		vi.erase(vi.begin(), vi.begin() + offset);
		std::cout << YELLOW << msg << offset << nl2reset;
		print_vector(vi);
		vi.erase(vi.begin(), vi.begin() + offset);
		std::cout << YELLOW << msg << offset << nl2reset;
		print_vector(vi);
		vi.erase(vi.begin(), vi.begin() + offset);
		std::cout << YELLOW << msg << offset << nl2reset;
		print_vector(vi);
		vi.erase(vi.begin(), vi.begin() + offset);
		std::cout << YELLOW << msg << offset << nl2reset;
		print_vector(vi);

		// vector is now empty, trying erase once more -> SegFault

		// vi.erase(vi.begin(), vi.begin() + offset);
		// std::cout << YELLOW << msg << offset << nl2reset;
		// print_vector(vi);
	}

	print_session_head(++i, "testing :: assign on vector<int>");

	{
		ft::vector<int>	A, B, C;
		int		arr[] = { 21, 42, 196883, 22, 43, 1024 };

		A.assign(7, 42); // size: 7

		B.assign(A.begin() + 1, A.end() - 1); // size: 5

		C.assign(arr, arr + 3); // 3

		std::cout << "Size of A: " << A.size() << nl;
		std::cout << "Size of B: " << B.size() << nl;
		std::cout << "Size of c: " << C.size() << nl2;

	}

	print_session_head(++i, "testing :: assign on vector<string>");

	{
		ft::vector<std::string>	A, B, C;

		std::string	arr[] = {
			"good ", "morning", "!",
			"hello ", "world", "?"
		};

		A.assign(7, "\%\% forty-two \%\%"); // size: 7

		B.assign(A.begin() + 1, A.end() - 1); // size: 5

		C.assign(arr, arr + 3); // 3

		std::cout << "Size of A: " << A.size() << nl;
		std::cout << "Size of B: " << B.size() << nl;
		std::cout << "Size of C: " << C.size() << nl2;

	}

	print_session_head(++i, "testing :: reserve");

	{
		// using namespace std;

		ft::vector<int>::size_type	z1, z2;
		ft::vector<int>	v1, v2;
		int	SIZE = 100;
		int	i;

		i = -1;
		while (++i < SIZE)
		{
			v1.push_back(i);
			if (z1 != v1.capacity())
			{
				z1 = v1.capacity();
				std::cout << "capacity changed: " << z1 << nl;
			}
		}
		std::cout << "size at last: " << v1.size() << nl;


		std::cout << "\n👆" 
		<< CROSS " no reserve :: 👇"
		<< TICK " with reserve " nl2; 


		i = -1;
		v2.reserve(64); // changed here
		while (++i < SIZE)
		{
			v2.push_back(i);
			if (z2 != v2.capacity())
			{
				z2 = v2.capacity();
				std::cout << "capacity changed: " << z2 << nl;
			}
		}
		std::cout << "size at last: " << v2.size() << nl2;

	}

	print_session_head(++i, "get_allocator for a *ptr to int[] ");

	{
		ft::vector<int>	v;
		int		Size = 12, i;
		int		*ptr;

		// allocate an array of SIZE elems using vector's own allocator

		ptr = v.get_allocator().allocate(Size);

		// construct values in-place
		i = -1;
		while (++i < Size)
			v.get_allocator().construct( & ptr[i], Size - i + 41);

		// print
		std::cout << "this allocated array contains: \n";
		i = -1;
		while (++i < Size)
			std::cout << ptr[i] << "\n";

		///	need overload but i don't want to write it
		// print_vector(ptr);


		// destroy and deallocate:
		i = -1;
		while (++i < Size)
			v.get_allocator().destroy (& ptr[i]);
		v.get_allocator().deallocate(ptr, Size);

	}

	print_session_head(++i, "Mazoise RESIZE test reproduced (1/2) :: std ");

	{
		std::vector<int>	test(12, 12);

		test.resize(72);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(100);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(4170);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(171, 12);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(62);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	}

	print_session_head(++i, "Mazoise RESIZE test reproduced (2/2) :: ft ");

	{
		ft::vector<int>	test(12, 12);

		test.resize(72);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(100);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(4170);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(171, 12);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
		test.resize(62);
		std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	}
	print_session_head(++i, "Mazoise INSERT test reproduced (1/2) :: std ");

	{
		std::vector<int> test(1, 1);
		std::vector<int> test2(5, 5);

		test.insert(test.begin(), 200, 12);
		print_vector_head(test);
		test.insert(test.begin() + 12, 200, 30);
		print_vector_head(test);
		test.insert(test.end(), 12, 50);
		print_vector_head(test);
		test.insert(test.end() - 1, 0, 60);
		print_vector_head(test);
		test.insert(test.end() - 1, 1, 70);
		print_vector_head(test);
		test.insert(test.begin() + 412, test2.begin(), test2.end());
		print_vector_head(test);
		test.insert(test.begin() + 6, test2.begin(), test2.end());
		print_vector_head(test);
		test.insert(test.end(), test2.begin(), test2.end());
		print_vector_head(test);
	}

	print_session_head(++i, "Mazoise INSERT test reproduced (2/2) :: ft ");

	{
		std::cout << std::endl << "INSERT TESTS" << std::endl;
		ft::vector<int> test(1, 1);
		ft::vector<int> test2(5, 5);

		test.insert(test.begin(), 200, 12);
		print_vector_head(test);
		test.insert(test.begin() + 12, 200, 30);
		print_vector_head(test);
		test.insert(test.end(), 12, 50);
		print_vector_head(test);
		test.insert(test.end() - 1, 0, 60);
		print_vector_head(test);
		test.insert(test.end() - 1, 1, 70);
		print_vector_head(test);
		test.insert(test.begin() + 412, test2.begin(), test2.end());
		print_vector_head(test);
		test.insert(test.begin() + 6, test2.begin(), test2.end());
		print_vector_head(test);
		test.insert(test.end(), test2.begin(), test2.end());
		print_vector_head(test);
	}

	print_session_head(++i, " capacity check :: push_back ");

	{
		int	i;

		std::vector<int>	v;

		i = 33;
		while (i++ < 43)
			v.push_back(i);
		std::cout << v.size() << " (size) - " << v.capacity() << " (capacity) \n";

		std::vector<int>	v2(v);
		std::cout << v2.size() << " (size) - " << v2.capacity() << " (capacity) \n";

		std::cout << "\n👆"
		<< " STD :: 👇"
		<< " FT " nl2;

		ft::vector<int>		v3 ;

		i = 33;
		while (i++ < 43)
			v3.push_back(i);
		std::cout << v3.size() << " (size) - " << v3.capacity() << " (capacity) \n";

		ft::vector<int>	v4(v3);
		std::cout << v4.size() << " (size) - " << v4.capacity() << " (capacity) \n";
	}

	print_session_head(++i, " capacity check :: assignment by = ");

	{

		int	i;

		std::vector<int>	v(10);
		ft::vector<int>		v3(10);

		i = -1;
		while (++i < 10)
			v[i] = 42;
		print_vector_head(v);


		std::vector<int>	v2(v);
		print_vector_head(v2);


		std::cout << "👆 STD :: 👇 FT " nl2;

		i = -1;
		while (++i < 10)
			v3[i] = 42;
		print_vector_head(v3);

		ft::vector<int>		v4(v3);
		print_vector_head(v4);

	}

	print_session_head(++i, "Mazoise COPY SWAP test reproduced (1/2) :: std ");

	{
		std::vector<int>	test;
		std::vector<int>	test_copy(test);

		for (size_t i = 0; i < 50; i++)
			test.push_back(i);
		for (size_t i = 0; i < test_copy.size(); i++)
			test_copy[i] += 100;
		print_vector_head(test_copy); /// commented out bcz identical result

		std::vector<int> test_range(test.begin() + 20, test.begin() + 30);
		print_vector_head(test_range);

		///*
		test_copy.swap(test);
		print_vector(test);
		print_vector_head(test_copy);

		///*
		test_copy.swap(test_range);
		print_vector_head(test_range);
		print_vector_head(test_copy);

		test.swap(test_copy);

		print_vector(test);
		print_vector_head(test_copy);
		//*/

	}
	std::cout << "👆 STD :: 👇 FT " nl2;
	print_session_head(++i, "Mazoise COPY SWAP test reproduced (2/2) :: ft ");
	{
		ft::vector<int>	test;
		ft::vector<int>	test_copy(test);

		for (size_t i = 0; i < 50; i++)
			test.push_back(i);
		for (size_t i = 0; i < test_copy.size(); i++)
			test_copy[i] += 100;
		print_vector_head(test_copy); /// commented out bcz identical result

		ft::vector<int>	test_range(test.begin() + 20, test.begin() + 30);
		print_vector_head(test_range);

		test_copy.swap(test);
		print_vector(test);
		print_vector_head(test_copy);

		///*
		test_copy.swap(test_range);
		print_vector_head(test_range);
		print_vector_head(test_copy);

		test.swap(test_copy);

		print_vector(test);
		print_vector_head(test_copy);
		//*/


	}


}

