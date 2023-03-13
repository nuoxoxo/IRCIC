#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "iostream"
#include "pair.hpp"
#include "util_enable_if.hpp"
#include "util_is_integral.hpp"
#include "iterator_reverse_iterator.hpp"
#include "red_black_tree.hpp" // incl. rbtIter

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public :
	};

	template<class Key, class T, class key_compare, class Alloc>
	bool operator == (
		const map<Key, T, key_compare, Alloc> & L,
		const map<Key, T, key_compare, Alloc> & R
	)
	{
		typename map<Key, T, key_compare, Alloc>::const_iterator it, it2;// = L .begin();

		L = L.begin();
		R = R.begin();
		if (L .size() != R .size())
			return false;
		while (it != L .end())
		{
			if (*it != *it2)
				return false;
			it++;
			it2++;
		}
		return true;
	}

}


#endif

