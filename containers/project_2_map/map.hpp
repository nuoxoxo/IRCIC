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
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public :
	};
}

#endif

