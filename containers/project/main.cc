#include "iostream"
#include "pair.hpp"

void	print_boolean_operator_test_result(ft::pair<int, int>&, ft::pair<int, int>&);

int	main()
{
	int	i = -1;

	std::cout << nl LOWKEY "Test :: " << ++i << " :: testing types" nl2reset;
	// same or different types
	{
		ft::pair<int, int>	ii;
		ft::pair<float, float>	ff;
		ft::pair<float, int>	fi;
		ft::pair<int, std::string> is;
		ft::pair<std::string, std::string> ss;
		
		ii = ft::pair<int, int>(21, 42);
		ff = ft::pair<float, float>(21.1024f, 42.2048f);
		fi = ft::pair<float, int>(42.42f, 1024);
		is = ft::pair<int, std::string>(1024, "Hello, World!");
		ss = ft::pair<std::string, std::string>("GoodMorning", "Vietnam!");
		
		print_pair(ii);
		print_pair(ff);
		print_pair(ss);
		print_pair(fi);
		print_pair(is);
	}
	std::cout << nl LOWKEY "Test :: " << ++i << " :: testing make_pair() " nl2reset;
	// testing make_pair
	{
		ft::pair<int, int> pii;
		pii = ft::make_pair<int, int>(20, 23);

		ft::pair<std::string, int> psi;
		psi = ft::make_pair<std::string, int>("A", 8);

		print_pair(pii);
		print_pair(psi);
	}
	// boolean operators
	std::cout << nl LOWKEY "Test :: " << ++i << " :: testing boolean operators " nl2reset;
	{
		ft::pair<int, int> p1, p2;

		p1 = ft::make_pair<int, int>(10, 20);
		p2 = ft::make_pair<int, int>(11, 20);
		print_boolean_operator_test_result(p1, p2);

		p1 = ft::make_pair<int, int>(11, 20);
		p2 = ft::make_pair<int, int>(10, 0);
		print_boolean_operator_test_result(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1024);
		p2 = ft::make_pair<int, int>(42, 1024);
		print_boolean_operator_test_result(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1024);
		p2 = ft::make_pair<int, int>(42, 1999);
		print_boolean_operator_test_result(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1999);
		p2 = ft::make_pair<int, int>(42, 1024);
		print_boolean_operator_test_result(p1, p2);

	}
}

void	print_boolean_operator_test_result(ft::pair<int, int> & p1, ft::pair<int, int> & p2)
{
	std::cout << GREEN "current pair: \n"
	<< p1.first << ", " << p1.second << "\n"
	<< p2.first << ", " << p2.second << "\n" RESET;

	std::cout << std::boolalpha;
	std::cout << " < : " << (p1 < p2) << nl;
	std::cout << " > : " << (p1 > p2) << nl;
	std::cout << " == : " << (p1 == p2) << nl;
	std::cout << " != : " << (p1 != p2) << nl;
	std::cout << " <= : " << (p1 <= p2) << nl;
	std::cout << " >= : " << (p1 >= p2) << nl2;
	std::cout << std::noboolalpha;

}

/********************************************
*  the main should test the following shit  *
*********************************************/

/* pair */

// = . assign contents
// make_pair()
//  ==
//  != 
//  < . <=
//  > . >=


/* stack */

// = . assign value to container adaptor
//  empty
//  size
//  top
//  push
//  pop
//  XXX emplace . constructs element in-place at the top
// Member objects: Container C . underlying container
//  ==
//  != 
//  < . <=
//  > . >=


