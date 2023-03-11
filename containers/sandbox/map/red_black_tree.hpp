#pragma once
#ifndef __RED_BLACK_TREE_HPP__
# define __RED_BLACK_TREE_HPP__

# include "iostream"

# include "iterator_red_black_tree_iterator.hpp"
# include "pair.hpp"
# include "util_swap.hpp"
# include "util_lexicographical_compare.hpp"

enum	e_tree_node_color
{
	RD,
	BK
};

namespace ft
{
	template< typename T, /* pair */ typename Key,
		class Allocator, class Compare >
	class red_black_tree
	{

	private:

		class	Node
		{

		public:

			T	data;
			Node	*left;
			Node	*right;
			Node	*parent;
			e_tree_node_color color;

		public:

			Node (const T & heart /* ptr */ = T ())
			: data(heart), left(0), right(0), parent(0) {}

		};

		typedef size_t	size_type;

		typedef typename
		allocator_type::template rebind<Node>::other node_allocator;


		Node		*m_root;//, *m_end;
		Node		*m_end;
		size_t		m_size;
		Compare		m_compare;
		node_allocator	m_allocator;

	public:

		typedef typename
		ft::red_black_tree_iterator<T, Node*, Compare>
			iterator;

		typedef typename
		ft::red_black_tree_iterator<const T, Node*, Compare>
			const_iterator;


		// gaia : constr, deconstr, make_node

		red_black_tree(
			const Compare & C = Compare(),
			const node_allocator & A = node_allocator()
		)
		{
			m_end = create_node();
			m_
			m_root = m_end;
			m_size = 0;

			m_allocator = A;
			m_compare_type = C;
		}

		~red_black_tree()
		{
			if (m_size) clear();
			_destroy_node(m_root);
		}

		Node	*create_node(const T &val = T ()) // default: RED
		{
			Node	*node; 

			node = m_allocator.construct(node, Node(val));
			node->parent = 0;
			node->left = 0;
			node->right = 0;
			node->color = RED;
			return (node);
		}


		// capapcity

		size_type max_size() const { return (m_allocator.max_size()); }
		size_type empty() const { return (!(m_size)); }
		size_type size() const { return (m_size()); }


		// accessor

		// begin . bg const
		// end . nd const
		// compare const

		// modifiers

		// insert
		// clear
		// swap (tree)
		// "node erase"
		// "range erase"

		// operations

		// count
		// lower_bound . upper bound . lb const . ub const
		// find . const


		// protected func
		// FIX tree
		// max node, min node
		// find T (pair)
		// insert when empty
		// delete
		// successor
		// replace
		// DOWN
		// LEFT ROT
		// RIGHT ROT
		// RED UNCLE FIX
		// 2 X BLACK FIX
		// SIBLING
		// is left kid
		// is right kid
		// has red kid
		// 
		// 
		//


		// o(^_^o) (o^_^)o





}

~red_black_tree()
{
	if (m_size)
		clear();
	_destroy_node(m_root);
}

	};
	// class red_black_tree ends

	// make stuff up
}

#endif

