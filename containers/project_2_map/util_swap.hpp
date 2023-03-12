#ifndef __SWAP_HPP__
# define __SWAP_HPP__

namespace ft
{
	template<typename T>
	void	swap(T & x, T &y)
	{
		T tmp = x;

		x = y;
		y = tmp;
	}

}

#endif
