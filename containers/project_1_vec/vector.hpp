#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "memory"
# include "iostream"
# include "stdexcept"

// # include "cstddef"
// # include "iterator"
// # include "algorithm"

# include "iterator_reverse_iterator.hpp"

# include "iterator_vector.hpp"
// # include "iterator_vector_const_iterator.hpp" /// depr

# include "util_lexicographical_compare.hpp"
# include "util_equal.hpp"
# include "util_swap.hpp"
# include "util_enable_if.hpp"
# include "util_is_integral.hpp"
// # include "util__swap.hpp" /// depr 


namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:
		// types:
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef Allocator								allocator_type;
		typedef size_t									size_type;
		typedef int										difference_type;
		typedef T										value_type;
		typedef ft::VectorIterator<pointer>				iterator;
		typedef ft::VectorIterator<const_pointer>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	private:
		size_type		m_size;
		size_type		m_capacity;
		allocator_type	m_allocator;
		value_type		* m_vector;

	public:
		explicit vector(const allocator_type & alloc = allocator_type()) // default
		{
			m_size = 0;
			m_capacity = 0;
			m_allocator = alloc;
			m_vector = m_allocator.allocate(0);
		}

		explicit vector(size_type n, const T & value = T(), const allocator_type& alloc = allocator_type()) // fill
		{
			m_size = n;
			m_capacity = n;
			m_allocator = alloc;
			m_vector = m_allocator.allocate(n);

			for (size_type i = 0; i < m_size; i++)
				m_allocator.construct(m_vector + i, value);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) // Check if is_integral, if yes, it's not an Iterator
		{
			m_size = 0;
			m_capacity = 0;
			m_allocator = alloc;
			m_vector = m_allocator.allocate(0);

			assign(first, last);
		}

		vector(const vector & L)
		{
			m_allocator = L.m_allocator;
			m_size = L.m_size;
			m_capacity = L.m_capacity;
			m_vector = m_allocator.allocate(m_capacity);

			for (size_type i = 0; i < m_size; i++)
			{
				m_allocator.construct(m_vector + i, *(L.m_vector + i));
			}
		}

		~vector()
		{
			clear();

			m_allocator.deallocate(m_vector, m_capacity);
		}

		vector & operator=(const vector & rhs)
		{
			if (*this == rhs)
				return *this;

			assign(rhs.begin(), rhs.end());

			return *this;
		}

		template<class InputIterator>
		void	assign(
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
			InputIterator>::type* = 0
		) // Check if is_integral, if yes, it's not an Iterator
		{
			clear();
			for (; first != last; first++)
			{
				push_back(*first);
			}
		}

		void	assign(size_type n, const T & val)
		{
			clear();
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}


		// method : get_allocator

		allocator_type get_allocator() const
		{
			return m_allocator;
		}


		// iterators:
		iterator	begin()
		{
			return iterator(m_vector);
		}

		const_iterator	begin() const
		{
			return const_iterator(m_vector);
		}

		iterator	end()
		{
			return iterator(m_vector + size());
		}

		const_iterator	end() const
		{
			return const_iterator(m_vector + size());
		}

		reverse_iterator	rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator	rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator	rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator	rend() const
		{
			return const_reverse_iterator(begin());
		}

		// capacity:
		size_type size() const
		{
			return m_size;
		}

		size_type	max_size() const
		{
			return m_allocator.max_size();
		}

		void	resize(size_type n, T c = T())
		{
			if (n > max_size())
				throw(std::length_error("vector::resize"));

			if (n <= size())
			{
				for (; m_size > n ; m_size--)
					m_allocator.destroy( & m_vector[m_size - 1]);
			}
			else
			{
				reserve(n);

				for (; m_size < n; m_size++)
					m_allocator.construct(m_vector + m_size, c);
			}
		}

		size_type capacity() const
		{
			return (m_capacity);
		}

		bool	empty() const
		{
			if (m_size != 0)
				return false;
			return true;
		}

		void	reserve(size_type n)
		{
			if (n > max_size())
			{
				throw(std::length_error("vector::reserve"));
			}
			if (n > capacity())
			{
				size_type	old_capacity = m_capacity;
				T			*tmp;

				m_capacity = n;
				tmp = m_allocator.allocate(m_capacity);

				for (size_type i = 0; i < m_size; i++)
				{
					m_allocator.construct(tmp + i, *(m_vector + i));
					m_allocator.destroy( & m_vector[i]);
				}

				m_allocator.deallocate(m_vector, old_capacity);
				m_vector = tmp;
			}
		}


		///	Accessors


		// []
		reference operator [] (size_type n)
		{
			return (*(m_vector + n));
		}

		const_reference operator [] (size_type n) const
		{
			return (*(m_vector + n));
		}


		// .at
		reference	at(size_type n)
		{
			if (n < 0 || n >= size())
				throw(std::out_of_range("vector::at"));
			return (*(m_vector + n));
		}

		const_reference	at(size_type n) const
		{
			if (n < 0 || n >= size())
				throw(std::out_of_range("vector::at const"));
			return (*(m_vector + n));
		}


		// .front & .back
		reference front()
		{
			return (*m_vector);
		}

		const_reference front() const
		{
			return (*m_vector);
		}

		reference back()
		{
			return (*(m_vector + (m_size - 1)));
		}

		const_reference back() const
		{
			return (*(m_vector + (m_size - 1)));
		}


		// modifiers:
		void push_back(const T & L)
		{
			if (m_capacity == 0)
				reserve(1);

			if (m_size == m_capacity)
				reserve(m_size * 2);

			T	*end = & m_vector[m_size];

			m_size++;
			m_allocator.construct(end, L);
		}

		void pop_back()
		{
			if (!empty())
			{
				m_size--;
				m_allocator.destroy( & m_vector[m_size]);
			}
		}

		iterator insert(iterator position, const T & L)
		{
			size_type	diff = position - begin();

			if (m_size + 1 > m_capacity)
			{
				reserve(m_size + 1);
			}

			for (size_type i = m_size; i > diff; i--)
			{
				m_allocator.construct( & m_vector[i], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}

			m_allocator.construct( & m_vector[diff], L);
			m_size++;

			return begin() + diff;
		}

		void insert(iterator position, size_type n, const T & L)
		{
			size_type	diff = position - begin();

			if (m_size + n > m_capacity)
			{
				reserve(m_size + n);
			}

			for (size_type i = m_size; i > diff; i--)
			{
				m_allocator.construct( & m_vector[i + n - 1], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}

			for (size_type i = 0; i < n; i++)
			{
				m_allocator.construct( & m_vector[diff + i], L);
			}

			m_size += n;
		}

		template<class InputIterator>
		void	insert(
			iterator position,
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
			InputIterator>::type* = 0
		)
		{
			difference_type	dist = 0;

			for (InputIterator tmp = last; tmp != first; tmp--)
				dist++;

			difference_type	diff = position - begin();

			if (m_size + dist > m_capacity)
				reserve(m_size + dist);

			for (difference_type i = m_size; i > diff; i--)
			{
				m_allocator.construct( & m_vector[i + dist - 1], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}

			for (difference_type i = 0; i < dist; i++)
			{
				m_allocator.construct( & m_vector[diff + i], *first);
				first++;
			}
			m_size += dist;
		}

		iterator erase(iterator position)
		{
			iterator it = position;
			iterator ite = end();
			iterator ret = it;

			if (position + 1 == ite)
			{
				pop_back();
			}
			else
			{
				for (; it + 1 != ite; it++)
				{
					m_allocator.destroy(it.base());
					m_allocator.construct(it.base(), *(it + 1));
				}
				m_allocator.destroy(it.base());
				m_size--;
			}

			return ret;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it = first;
			iterator ret;
			for (; first != last; ++first)
				ret = erase(it);

			return ret;
		}

		void	swap(vector & L)
		{
			if (*this == L)
				return ;
			ft::swap(m_size, L.m_size);
			ft::swap(m_capacity, L.m_capacity);
			ft::swap(m_vector, L.m_vector);
		}

		void	clear()
		{
			for (size_type i = 0; i < m_size; i++)
				m_allocator.destroy(m_vector + i);
			m_size = 0;
		}
	};

	template<class T, class Allocator>
	bool	operator == (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		if (L.size() != R.size())
			return false;
		for (size_t i = 0; i < L.size(); i++)
		{
			if (L[i] != R[i])
				return false;
		}
		return (true);
	}

	template<class T, class Allocator>
	bool operator != (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		return (!(L == R));
	}

	template<class T, class Allocator>
	bool operator < (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		return (ft::lexicographical_compare(L.begin(), L.end(), R.begin(), R.end()));
	}

	template<class T, class Allocator>
	bool operator> (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		return (R < L);
	}

	template<class T, class Allocator>
	bool operator >= (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		return (!(L < R));
	}

	template<class T, class Allocator>
	bool operator <= (
		const vector<T,Allocator> & L, 
		const vector<T,Allocator> & R
	)
	{
		return (!(R < L));
	}

	// specialized algorithms:
	template<class T, class Allocator>
	void swap(vector<T,Allocator> & L, vector<T,Allocator> & R)
	{
		L.swap(R);
	}
}

#endif
