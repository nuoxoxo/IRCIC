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
		typedef Key				key_type;
		typedef T				mapped_type;
		typedef Compare			key_compare;
		typedef Allocator 		allocator_type;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;

		typedef ft::pair<const key_type, mapped_type>		value_type;

		typedef typename
		allocator_type::reference	reference;
		typedef typename
		allocator_type::const_reference	const_reference;

		typedef typename
		allocator_type::pointer		pointer;
		typedef typename
		allocator_type::const_pointer	const_pointer;

		typedef typename 
		ft::red_black_tree<value_type, key_type, key_compare, allocator_type> tree_type;

		typedef typename
		tree_type::iterator		iterator;
		typedef typename
		tree_type::const_iterator	const_iterator;

		typedef typename
		ft::reverse_iterator<iterator>		reverse_iterator;
		typedef typename
		ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		class	value_compare : std::binary_function<value_type, value_type, bool>
		{
		friend class map;

		protected :
			key_compare	compare;
			value_compare(key_compare c) : compare(c) {}

		public :
			bool operator()(const value_type& x, const value_type& y) const { return compare(x.first, y.first); }
		};


	private :
		tree_type	m_tree;


	public :
		explicit map(const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type())
		{
			static_cast<void>(compare);
			static_cast<void>(alloc);
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& compare = key_compare(), const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			static_cast<void>(compare);
			static_cast<void>(alloc);
			insert(first, last);
		}

		map(const map& x)
		{
			insert(x.begin(), x.end());
		}

		~map()
		{
		}

		map &operator=(const map &R )
		{
			if (*this != R )
			{
				clear();
				insert(R .begin(), R .end());
			}
			return *this;
		}

		// ==================== Iterators

		iterator begin()
		{
			return m_tree.begin();
		}

		const_iterator begin() const
		{
			return m_tree.begin();
		}

		iterator end()
		{
			return m_tree.end();
		}

		const_iterator end() const
		{
			return m_tree.end();
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(m_tree.end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(m_tree.end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(m_tree.begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(m_tree.begin());
		}

		// ==================== Capacity

		bool empty() const
		{
			return m_tree.empty();
		}

		size_type size() const
		{
			return m_tree.size();
		}

		size_type max_size() const
		{
			return m_tree.max_size();
		}

		// ==================== Elements access

		mapped_type& operator[](const key_type& k)
		{
			return (insert(ft::make_pair(k, mapped_type())).first)->second;
		}

		// ==================== Modifiers

		pair<iterator, bool> insert(const_reference x)
		{
			return m_tree.insert(x);
		}

		iterator insert(iterator position, const value_type& x)
		{
			(void)position;
			return m_tree.insert(x).first;
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last ; first++)
				m_tree.insert(*first);
		}

		void erase(iterator position)
		{
			erase(position->first);
		}

		size_type erase(const key_type& k)
		{
			return m_tree.node_erase(ft::make_pair(k, mapped_type()));
		}

		void erase(iterator first, iterator last)
		{
			m_tree.range_erase(first, last);
		}

		void swap(map& x)
		{
			m_tree.swap_tree(x.m_tree);
		}

		void clear()
		{
			if (size())
				m_tree.clear();
		}

		// ==================== Observers

		key_compare key_comp() const
		{
			return key_compare();
		}

		value_compare value_comp() const
		{

			return value_compare(m_tree.compare());
		}

		// ==================== Operations

		iterator find(const key_type& k)
		{
			return m_tree.find(ft::make_pair(k, mapped_type()));
		}

		const_iterator find(const key_type& k) const
		{
			return m_tree.find(ft::make_pair(k, mapped_type()));
		}

		size_type count(const key_type& k) const
		{
			return m_tree.count(ft::make_pair(k, mapped_type()));
		}

		iterator lower_bound(const key_type& k)
		{
			return m_tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator lower_bound(const key_type& k) const
		{
			return m_tree.lower_bound(ft::make_pair(k, mapped_type()));
		}

		iterator upper_bound(const key_type& k)
		{
			return m_tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		const_iterator upper_bound(const key_type& k) const
		{
			return m_tree.upper_bound(ft::make_pair(k, mapped_type()));
		}

		pair<iterator, iterator> equal_range(const key_type& k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type& k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		allocator_type get_allocator() const
		{
			return allocator_type();
		}

	};


	template<class Key, class T, class Compare, class Allocator>
	bool operator == (
		const map<Key, T, Compare, Allocator> & L,
		const map<Key, T, Compare, Allocator> & R
	)
	{
		typename map<Key, T, Compare, Allocator>::const_iterator	it;
		typename map<Key, T, Compare, Allocator>::const_iterator	it2;

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
	{	return ( ft::lexicographical_compare(L.begin(), L.end(), R.begin(), R.end()) );	}

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
		return (!(L == R));
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

