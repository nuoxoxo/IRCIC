#ifndef __PAIR_HPP__
# define __PAIR_HPP__
# define nl "\n"

// TODO - comparison operators 

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
};

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


template<typename L, typename R>
void	print_pair(ft::pair<L, R> p)
{
	std::cout << p.first << ' ' << p.second << nl;
}

#endif
