#ifndef __PAIR_HPP__
# define __PAIR_HPP__

// color tags
# define nl "\n"
# define nl2 "\n\n"
# define nl2reset " \n\n" RESET
# define LOWKEY "\033[0;2m"
# define GREEN "\033[0;32m"
# define RESET "\033[0;0m"

namespace	ft
{
	template<typename T_1, typename T_2>
	class	pair
	{

	public:
		T_1	first;
		T_2	second;
	public:

		// canon
		pair() : first(), second() {}
		~pair() {}

		pair(const T_1 & l, const T_2 & r) : first(l), second(r) {}
		
		template<typename L, typename R>
		pair(const pair<L, R> & p) : first(p.first), second(p.second) {}


		// operator
		pair & operator = (const pair & p)
		{
			if (this != & p)
				first = p.first, second = p.second;
			return (*this);
		}

	};

	template<typename L, typename R>
	pair<L, R> make_pair(L l, R r) { return (pair<L, R>(l, r)); }


	// == . !=
	template<typename T_1, typename T_2>
	bool	operator == (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		return (L.first == R.first && L.second == R.second);
	}

	template<typename T_1, typename T_2>
	bool	operator != (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		return (L.first != R.first || L.second != R.second);
	}


	// < >
	template<typename T_1, typename T_2>
	bool	operator < (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		if (L.first == R.first)
			return L.second < R.second;
		return L.first < R.first;
	}

	template<typename T_1, typename T_2>
	bool	operator > (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		if (L.first == R.first)
			return L.second > R.second;
		return L.first > R.first;
	}


	// <= >=
	template <typename T_1, typename T_2>
	bool	operator <= (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		return (L < R || L == R);
	}

	template<typename T_1, typename T_2>
	bool	operator >= (const pair<T_1, T_2> & L, const pair<T_1, T_2> & R)
	{
		return (L > R || L == R);
	}

};

template<typename L, typename R>
void	print_pair(ft::pair<L, R> p)
{
	std::cout << p.first << ' ' << p.second << nl;
}

/* ****************************************
 *  type test, operator test              *
 * ****************************************/

void	printer_boolean_operator_test(ft::pair<int, int>&, ft::pair<int, int>&);

// int	main() // i just move main body here
void	pair_test(void)
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
		printer_boolean_operator_test(p1, p2);

		p1 = ft::make_pair<int, int>(11, 20);
		p2 = ft::make_pair<int, int>(10, 0);
		printer_boolean_operator_test(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1024);
		p2 = ft::make_pair<int, int>(42, 1024);
		printer_boolean_operator_test(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1024);
		p2 = ft::make_pair<int, int>(42, 1999);
		printer_boolean_operator_test(p1, p2);

		p1 = ft::make_pair<int, int>(42, 1999);
		p2 = ft::make_pair<int, int>(42, 1024);
		printer_boolean_operator_test(p1, p2);

	}
}

void	printer_boolean_operator_test(ft::pair<int, int> & p1, ft::pair<int, int> & p2)
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


#endif
