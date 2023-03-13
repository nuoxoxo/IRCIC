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


	template<class Key, class T, class Compare, class Allocator>
	bool operator == (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R
	)
	{
		typename
		map<Key, T, key_compare, Allocator>::const_iterator	it, it2;

		if (L.size() != R.size())
		{
			return (false);
		}
		L = L.begin();
		R = R.begin();
		while (it != L.end())
		{
			if (*it != *it2)
			{
				return (false);
			}
			it++;
			it2++;
		}
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator < (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R
	)
	{	return ( ft::lexicographical_compare(L.begin(), L.end(), R.begin(), R.end() );	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator > (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R
	)
	{
		return (R < L);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator != (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R)
	{
		return (!(L== R));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator <= (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R)
	{
		return (!(R < L));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool operator >= (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R)
	{
		return (!(L < R));
	}

	template<class Key, class T, class Compare, class Allocator>
	void	swap(
		map<Key, T, Compare, Allocator> & L,
		map<Key, T, Compare, Allocator> & R
	)
	{
		return L.swap(R);
	}



}


#endif

