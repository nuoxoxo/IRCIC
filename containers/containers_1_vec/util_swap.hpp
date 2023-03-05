#ifndef ___SWAP_HPP__
# define ___SWAP_HPP__

namespace ft
{
	template<typename T>
	void	_swap(T & x, T &y)
	{
		T tmp = x;

		x = y;
		y = tmp;
	}

}

#endif
