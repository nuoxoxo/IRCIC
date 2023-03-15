#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "iostream"

// FIXME
// # include "memory" // home::deletable
// # include "stdexcept" // home::deletable

# include "algorithm"
# include "iterator_reverse_iterator.hpp"
# include "util_lexicographical_compare.hpp"
# include "util_equal.hpp"
# include "util_swap.hpp"
# include "util_enable_if.hpp"
# include "util_is_integral.hpp"


namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:
		// types:
		typedef typename Allocator::reference	reference;
		typedef typename Allocator::pointer	pointer;

		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::const_pointer	const_pointer;

		typedef Allocator	allocator_type;
		typedef T		value_type;
		typedef size_t		size_type;

		typedef ptrdiff_t	difference_type;
		// typedef int		difference_type; // int works just as fine

		typedef pointer			iterator;
		typedef const_pointer	const_iterator;

		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:

		size_type		m_size;
		size_type		m_capacity;
		value_type		* m_vector;
		allocator_type		m_allocator;

		size_type	_get_next_size(size_type) const;


	public:

		// default
		explicit vector(const allocator_type & alloc = allocator_type())
		{
			m_size = 0;
			m_capacity = 0;
			m_allocator = alloc;
			m_vector = m_allocator.allocate(0);
		}


		// fill
		explicit vector(
			size_type	n,
			const		T & value = T(),
			const		allocator_type& alloc = allocator_type()
		)
		{
			size_type	i;

			m_size = n;
			m_capacity = n;
			m_allocator = alloc;
			m_vector = m_allocator.allocate(n);

			i = -1;
			while (++i < m_size)
				m_allocator.construct(m_vector + i, value);
		}
		// FIXED - mar 10 :: Fixed mazoise copy-swap test @ 381c381
		// FIXME - mar 9 :: corr. failed mazoise copy-swap @ Segfault
		// FIXME - mar 8 :: failed mazoise copy-swap test @ 381c381
		/*
		{
			m_allocator = alloc;
			m_size = 0;
			m_capacity = 0;
			m_vector = m_allocator.allocate(0);
			assign(first, last);

			// FIXME - found the problem cf. mazoise copy-swap test ~~
		}
		{
			m_allocator = alloc;

			m_size = std::distance(first, last);
			m_capacity = std::distance(first, last);
			m_vector = m_allocator.allocate(m_capacity);

			// std::copy(first, last, begin());
			// FIXME - is Segfault caused by std::copy ? No.

			assign(first, last); // is Segfault caused by std::copy ? No.
		}
		*/

		// range
		template<class InputIterator>
		vector(InputIterator first, InputIterator last,
			const allocator_type & alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = 0
		) : m_size(0), m_capacity(0), m_allocator(alloc)
		{
			m_vector = m_allocator.allocate(0);
			assign(first, last);
			// Fixed by this line
			m_capacity = std::distance(first, last);
		}


		vector(const vector & val)
		{
			size_type	i;

			m_allocator = val.m_allocator;
			m_size = val.m_size;
			m_capacity = val.m_size ;
			m_vector = m_allocator.allocate(m_capacity);

			i = -1;
			while (++i < m_size)
			{
				m_allocator.construct(m_vector + i, *(val.m_vector + i));
			}
		}

		~vector()
		{
			clear();
			m_allocator.deallocate(m_vector, m_capacity);
		}

		vector & operator = (const vector & dummy)
		{
			if (*this == dummy)
				return *this;

			assign(dummy.begin(), dummy.end());

			return (*this);
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
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void	assign(size_type n, const T & val)
		{
			size_type	i;

			clear();
			i = -1;
			while (++i < n)
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
			return iterator(m_vector + m_size);
		}

		const_iterator	end() const
		{
			return const_iterator(m_vector + m_size);
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


		void	resize(size_type size, T c = T())
		{
			if (size > m_size)
			{
				reserve(_get_next_size(size));
				insert(end(), size - m_size, c);
			}
			else if (size < m_size)
			{
				erase(begin() + size, end());
			}
		}
		// FIXED - mar 10 :: concise++ improvement
		// FIXME - mar 9 :: passed resize @ 25c25 failed the rest
		// FIXED - mar 8 :: mine, failed resize test @ 25c25
		/*
		{
			// FIXME - passed resize @ 25c25 failed others

			size_type	Size;

			Size = m_size;
			if (n < Size)
			{
				while (m_size > n)
				{
					m_allocator.destroy( & m_vector[m_size - 1]);
					m_size--;
				}
			}
			else if (n > m_capacity)
			{
				Size = m_capacity * 2 < n ? n : m_capacity * 2;

				reserve(Size);
			}
			while (m_size < n)
			{
				m_allocator.construct(m_vector + m_size, c);
				m_size++;
			}
		}
		{
			// FIXME - failed resize test @ 25c25

			if (n < m_size)
			{
				while (m_size > n)
				{
					m_allocator.destroy( & m_vector[m_size - 1]);
					--m_size;
				}
				return ;
			}
			reserve(n);
			while (m_size < n)
			{
				m_allocator.construct(m_vector + m_size, c);
				++m_size;
			}
		}
		*/


		size_type capacity() const
		{
			return (m_capacity);
		}


		bool	empty() const
		{
			return ((m_size) ? false : true);
			/*
			if (m_size != 0)
				return false;
			return true;
			*/
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
				size_type	i;
				T		*tmp;

				m_capacity = n;
				tmp = m_allocator.allocate(m_capacity);

				i = -1;
				while (++i < m_size)
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
			if (n < 0 || n >= m_size)
				throw(std::out_of_range("vector::at"));
			return (*(m_vector + n));
		}

		const_reference	at(size_type n) const
		{
			if (n < 0 || n >= m_size)
				throw(std::out_of_range("vector::at const"));
			return (*(m_vector + n));
		}


		// .front & .back
		reference	front()
		{
			return (*m_vector);
		}

		const_reference	front() const
		{
			return (*m_vector);
		}

		reference	back()
		{
			return (*(m_vector + (m_size - 1)));
		}

		const_reference back() const
		{
			return (*(m_vector + (m_size - 1)));
		}


		// modifiers:
		void	push_back(const T & val)
		{
			if (m_capacity == 0)
				reserve(1);

			if (m_size == m_capacity)
				reserve(m_size * 2);

			T	*end = & m_vector[m_size];

			m_size++;
			m_allocator.construct(end, val);
		}

		void	pop_back()
		{
			if (empty())
				return ;
			m_size--;
			m_allocator.destroy( & m_vector[m_size]);
		}


		iterator insert(iterator position, const T & val)
		{

			// std::cout << RED << __FUNCTION__ << " called 1 (single element)" << RESET nl2reset;

			size_type	offset = position - begin();
			size_type	i;

			if (m_size + 1 > m_capacity)
			{
				reserve(m_size > 0 ? m_size * 2 : 1);
			}
			i = m_size + 1;
			while (--i > offset)
			{
				m_allocator.construct( & m_vector[i], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}
			m_allocator.construct( & m_vector[offset], val);
			m_size++;
			return (begin() + offset);
		}


		void	insert(iterator position, size_type n, const T & val)
		{
			size_type	i;

			if (m_capacity < m_size + n)
			{
				size_type	diff;

				diff = position - begin();

				reserve(m_size + n > m_size * 2 ? m_size + n : m_size * 2);
				position = begin() + diff;
			}
			i = -1;
			while (++i < n)
				position = insert(position, val) + 1;

		}
		// FIXME -  mar 8 :: cf. mazoise Resize & Insert tests
		/*
		{
			size_type	diff = position - begin();

			if (m_size + n > m_capacity)
			{
				reserve(m_size + std::max(m_size, n));
			}
			for (size_type i = m_size; i > diff; i--)
			{
				m_allocator.construct( & m_vector[i + n - 1], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}
			for (size_type i = 0; i < n; i++)
			{
				m_allocator.construct( & m_vector[diff + i], val);
			}
			m_size += n;
		}
		*/


		template<class InputIterator>
		void	insert(
			iterator	position,
			InputIterator	first,
			InputIterator	last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value,
				InputIterator>::type* = 0
		)
		{
			difference_type	dist = 0;
			difference_type	diff;
			difference_type	i;
			InputIterator	it;

			it = last;
			while (it > first)
			{
				++dist;
				--it;
			}
			diff = position - begin();
			if (m_size + dist > m_capacity)
			{
				reserve(m_size + std::max(m_size, (size_type) dist));
			}
			i = m_size + 1;
			while (--i > diff)
			{
				m_allocator.construct( & m_vector[i + dist - 1], m_vector[i - 1]);
				m_allocator.destroy( & m_vector[i - 1]);
			}
			i = -1;
			while (++i < dist)
			{
				m_allocator.construct( & m_vector[diff + i], *first);
				++first;
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
				while (it + 1 != ite)
				{
					m_allocator.destroy(it);
					m_allocator.construct(it, *(it + 1));
					++it;
				}
				m_allocator.destroy(it);
				m_size--;
			}
			return ret;
		}

		iterator erase(iterator first, iterator last)
		{
			iterator	res;
			iterator	it;

			it = first;
			while (first < last)
			{
				res = erase(it);
				++first;
			}
			return res;
		}

		void	swap(vector & val)
		{
			if (*this == val)
				return ;
			ft::swap(m_size, val.m_size);
			ft::swap(m_capacity, val.m_capacity);
			ft::swap(m_vector, val.m_vector);
		}

		void	clear()
		{
			size_type	i = -1;

			while (++i < m_size)
				m_allocator.destroy(m_vector + i);
			m_size = 0;
		}
	};

	template<class T, class Allocator>
	bool	operator == (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		typedef typename vector<T, Allocator>::const_iterator it_type;

		if (L.size() ^ R.size())
			return false;
		return ft::equal<it_type, it_type>(L.begin(), L.end(), R.begin());

	}
	/*
	{
		if (L.size() != R.size())
			return false;
		for (size_t i = 0; i < L.size(); i++)
		{
			if (L[i] == R[i])
				continue ;
			return false;
		}
		return (true);
	}
	*/

	template<class T, class Allocator>
	bool operator != (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		return (!(L == R));
	}

	template<class T, class Allocator>
	bool operator < (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		return (ft::lexicographical_compare(L.begin(), L.end(), R.begin(), R.end()));
	}

	template<class T, class Allocator>
	bool operator > (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		return (R < L);
	}

	template<class T, class Allocator>
	bool operator >= (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		return (!(L < R));
	}

	template<class T, class Allocator>
	bool operator <= (
		const vector<T, Allocator> & L, 
		const vector<T, Allocator> & R
	)
	{
		return (!(R < L));
	}

	template<class T, class Allocator>
	void swap(vector<T, Allocator> & L, vector<T, Allocator> & R)
	{
		L.swap(R);
	}

}


template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type 
ft::vector<T, Allocator>::_get_next_size(size_type size) const
{
	size_type	res;

	res = size > max_size() / 2 ? max_size() : m_capacity * 2;
	if (!res)
		res = 1;
	if (res < size)
		return (size);
	return (res);
}


#endif
