#include "iostream"
#include "ft_pair.hpp"

int	main()
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

	// testing make_pair

	ft::pair<int, int> pii;
	pii = ft::make_pair<int, int>(20, 23);

	ft::pair<std::string, int> psi;
	psi = ft::make_pair<std::string, int>("A", 8);

	print_pair(pii);
	print_pair(psi);
}
