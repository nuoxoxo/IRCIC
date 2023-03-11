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
	template<typename T, /* pair */ typename Key,
		class Allocator, class Compare>
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

	};
	// class red_black_tree ends

	// make stuff up
}

#endif

