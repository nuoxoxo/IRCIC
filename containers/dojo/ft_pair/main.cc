#include "iostream"
#include "ft_pair.hpp"

int	main()
{
	ft::pair<int, int>	ii;
	ii = ft::pair<int, int>(21, 42);
	
	ft::pair<float, float>	ff;
	ff = ft::pair<float, float>(21.1024f, 42.2048f);
	
	ft::pair<std::string, std::string>	ss;
	ss = ft::pair<std::string, std::string>("GoodMorning", "Vietnam!");

	ft::pair<float, int>	fi;
	fi = ft::pair<float, int>(42.42f, 1024);

	ft::pair<int, std::string>	is;
	is = ft::pair<int, std::string>(1024, "Hello, World!");
	
	print_pair(ii);
	print_pair(ff);
	print_pair(ss);
	print_pair(fi);
	print_pair(is);
}
