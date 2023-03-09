#pragma once
#ifndef __ITERATOR_RED_BLACK_TREE_ITERATOR_HPP__
# define __ITERATOR_RED_BLACK_TREE_ITERATOR_HPP__

# include "pair.hpp"
# include "red_black_tree.hpp"
# include "iterator_traits.hpp"

namespace ft
{
	template<typename T, // type: pair
		typename Node,
		typename /*class*/ Compare
	>
	class rbt_iterator : // inherit from ft::Iter
	ft::iterator<ft::bidirectional_iterator_tag, Node>
	{

	protected:
		Node	m_curr;

	public:
		typedef typename ft::iterator_traits<Node>::value_type
			value_type;

		typedef typename ft::iterator_traits<Node>::difference_type
			difference_type;

		typedef typename ft::iterator_traits<Node>::iterator_category
			iterator_category;

		typedef T *pointer;
		typedef T &reference;

	public:
		rbt_iterator() : m_curr() {}

		rbt_iterator(Node node) : m_curr(node) {}

		rbt_iterator(const rbt_iterator & it) : m_curr(it.m_curr) {}

		rbt_iterator & operator = (const rbt_iterator & it)
		{
			if (this != & it)
			{
				m_curr = it.m_curr;
			}
			return (*this);
		}

		


	}

	// make stuff up
}

#endif
