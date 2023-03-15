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
		class /*typename*/ Compare>
		//typename /*class*/ Compare>
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
		Node	m_current;

	public:
		typedef typename
		ft::iterator_traits<Node>::value_type	value_type;

		typedef typename
		ft::iterator_traits<Node>::difference_type difference_type;

		typedef typename
		ft::iterator_traits<Node>::iterator_category iterator_category;

		typedef T *	pointer;
		typedef T &	reference;
		typedef Node	node_pointer ;

	public:
		// canon

		red_black_tree_iterator() : m_current(NULL) {}
		red_black_tree_iterator(Node node) : m_current(node) {}

		red_black_tree_iterator(const red_black_tree_iterator & it)
		: m_current(it.m_current) {}


		red_black_tree_iterator & operator = (const red_black_tree_iterator & it)
		{
			if (this != & it)
				m_current = it.m_current;
			return (*this);
		}


		operator red_black_tree_iterator<const T, Node, Compare> () const
		{
			return
			(red_black_tree_iterator<const T, Node, Compare>(m_current));
		}


		Node  base() const
		{
			return (m_current);
		}


		friend bool operator == (
			const red_black_tree_iterator<T, Node, Compare> & L,
			const red_black_tree_iterator<T, Node, Compare> & R
		)
		{
			return (L.base() == R.base());
		}

		friend bool operator != (
			const red_black_tree_iterator<T, Node, Compare> & L,
			const red_black_tree_iterator<T, Node, Compare> & R
		)
		{
			return (L.base() != R.base());
		}

		reference operator * () const
		{
			return (m_current->data);
		}

		pointer operator -> () const
		{
			return ( &(m_current->data) );
		}

		// post icr
		red_black_tree_iterator operator ++ (int)
		{
			red_black_tree_iterator	it(*this);

			operator ++ ();
			return (it);
		}

		// pre icr
		red_black_tree_iterator & operator ++ ()
		{
			// TODO
			if (m_current && m_current->right)
			{
				m_current = m_current->right;
				while (m_current->left)
					m_current = m_current->left;
			}
			else if (m_current && m_current->parent)
			{
				Node	curr, temp;

				curr = m_current;
				temp = m_current->parent;
				while (temp && m_current == temp->right)
				{
					if (temp->parent == 0)
					{
						m_current = curr->parent;
						return (*this);
					}
					m_current = temp;
					temp = temp->parent;
				}
				m_current = temp;
			}
			return (*this);
		}

		// post dcr
		red_black_tree_iterator operator -- (int)
		{
			red_black_tree_iterator	it(*this);

			operator -- ();
			return (it);
		}

		// pre dcr
		red_black_tree_iterator & operator -- ()
		{
			// TODO
			if (m_current && m_current->left)
			{
				m_current = m_current->left;
				while (m_current->right && m_current->right)
				{
					m_current = m_current->right;
				}
			}
			else if (m_current && m_current->parent)
			{
				Node curr = m_current;
				Node temp = m_current->parent;
				while (temp && m_current == temp->left)
				{
					if (temp->parent == 0)
					{
						m_current = curr;
						return (*this);
					}
					m_current = temp;
					temp = temp->parent;
				}
				m_current = temp;
			}
			return (*this);
		}

	};

}

#endif
