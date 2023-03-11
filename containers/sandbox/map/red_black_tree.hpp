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
	template<typename T, /* pair */ typename Key, // key type
		class Compare, class Allocator>
	class red_black_tree
	{

	private:
		typedef T value_type;

	public: // should be private // FIXME
		class	Node
		{

		public:
			e_tree_node_color	color;
			value_type		data;
			Node			*left;
			Node			*right;

		public:
			Node (const value_type & val /* ptr */ = value_type())
			: data(val), left(0), right(0), parent(0) {}

		};


		// type typedef session
		// TODO


		// node typedef session
		// TODO


		// private session of m_ attributes
		// TODO
	
	// 

	public:

	};
	// class red_black_tree ends

	// make stuff up
}

#endif

