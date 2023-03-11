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
	class red_black_tree_iterator : // inherit from ft::Iter
	ft::iterator<ft::bidirectional_iterator_tag, Node>
	{

	/*
	1. A red-black tree T
		is a binary search tree having following five additional properties

	2. Root of T is black.

	3. Every node in T is either red or black.
		- The root node of T is black.
		- Every nil node is black.
		- nil nodes are the leaf nodes, which do not contain any keys.
		- if a key that is not present in the tree, we reach the nil node.

	4. If a node is red, both of its children are black. 
		-  ie. No two nodes on a path can be red nodes.

	5. Every path from root to nil has the same number of black nodes.
	*/

	// https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

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
		red_black_tree_iterator() : m_curr() {}
		red_black_tree_iterator(Node node) : m_curr(node) {}
		red_black_tree_iterator(const red_black_tree_iterator & it) : m_curr(it.m_curr) {}

		red_black_tree_iterator & operator = (const red_black_tree_iterator & it)
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
