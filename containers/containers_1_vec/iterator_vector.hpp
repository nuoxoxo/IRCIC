#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

# include "iterator"
# include "cstddef"
# include "iterator_vector_const_iterator.hpp"

namespace ft
{
	template<typename T>
	class	vector_iterator
	{

	private:
		pointer m_ptr;

	public:
		typedef std::random_access_iterator_tag iterator_category; // ***
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::ptrdiff_t difference_type; // ***

		vector_iterator(void) : m_ptr(NULL) {}
		explicit vector_iterator(pointer ptr) : m_ptr(ptr) {}
		vector_iterator(vector_iterator const& copy) : m_ptr(copy.m_ptr) {}
		virtual ~vector_iterator(void) {}

		vector_iterator& operator=(vector_iterator const& assign)
		{
			if (this != &assign)
				m_ptr = assign.m_ptr;
			return *this;
		}

		operator vector_const_iterator<T>(void) const
		{
			return vector_const_iterator<T>(m_ptr);
		}

		reference operator*(void) { return *m_ptr; }
		pointer operator->(void) { return m_ptr; }
		reference operator[](difference_type n) { return *(m_ptr + n); }

		bool operator == (vector_iterator const& x) const { return m_ptr == x.m_ptr; }
		bool operator != (vector_iterator const& x) const { return m_ptr != x.m_ptr; }
		bool operator < (vector_iterator const& x) const { return m_ptr < x.m_ptr; }
		bool operator > (vector_iterator const& x) const { return m_ptr > x.m_ptr; }
		bool operator <= (vector_iterator const& x) const { return m_ptr <= x.m_ptr; }
		bool operator >= (vector_iterator const& x) const { return m_ptr >= x.m_ptr; }

		vector_iterator& operator++(void)
		{
			m_ptr++;
			return *this;
		}

		vector_iterator operator++(int)
		{
			vector_iterator temp(*this);
			++(*this);
			return temp;
		}

		vector_iterator& operator--(void)
		{
			m_ptr--;
			return *this;
		}

		vector_iterator operator--(int)
		{
			vector_iterator temp(*this);
			--(*this);
			return temp;
		}

		vector_iterator& operator+=(difference_type i)
		{
			m_ptr += i;
			return *this;
		}

		vector_iterator& operator-=(difference_type i)
		{
			m_ptr -= i;
			return *this;
		}

		vector_iterator operator+(difference_type i) const
		{
			return vector_iterator(m_ptr + i);
		}

		friend vector_iterator operator+(difference_type i,
				vector_iterator const& x)
		{
			return vector_iterator(x + i);
		}

		vector_iterator operator-(difference_type i) const
		{
			return vector_iterator(m_ptr - i);
		}

		difference_type operator-(vector_iterator const& x) const
		{
			return m_ptr - x.m_ptr;
		}

	};
}

#endif
