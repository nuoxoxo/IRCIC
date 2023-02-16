#include "iostream"

#define nl "\n"

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
		pair & operator = (const pair & dummy)
		{
			if (this != & dummy)
			{
				first = dummy.first;
				second = dummy.second;
			}
			return (*this);
		}

	};

	template<typename L, typename R>
	pair<L, R> make_pair(L l, R r) { return (pair<L, R>(l, r)); }
};

template<typename X, typename Y>
void	print_pair(ft::pair<X, Y> p)
{
	std::cout << p.first << ' ' << p.second << nl;
}
