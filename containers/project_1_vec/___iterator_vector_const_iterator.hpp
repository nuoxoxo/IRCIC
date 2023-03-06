#ifndef __ITERATOR_VECTOR_CONST_ITERATOR_HPP__
# define __ITERATOR_VECTOR_CONST_ITERATOR_HPP__

# include "iterator"
# include "cstddef"

namespace   ft
{
	template <typename T>
	class   vector_const_iterator
	{



	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef T const& reference;
		typedef T const* pointer;
		typedef std::ptrdiff_t difference_type;

		vector_const_iterator(void) : m_ptr(NULL) {}
		explicit vector_const_iterator(pointer ptr) : m_ptr(ptr) {}
		vector_const_iterator(vector_const_iterator const& copy) : m_ptr(copy.m_ptr) {}
		virtual ~vector_const_iterator(void) {}

		vector_const_iterator& operator=(vector_const_iterator const& assign)
		{
			if (this != &assign)
				m_ptr = assign.m_ptr;
			return *this;
		}

		reference operator*(void) const { return *m_ptr; }
		pointer operator->(void) const { return m_ptr; }
		reference operator[](difference_type n) const { return *(m_ptr + n); }

		bool operator == (vector_const_iterator const& x) const { return m_ptr == x.m_ptr; }
		bool operator != (vector_const_iterator const& x) const { return m_ptr != x.m_ptr; }
		bool operator < (vector_const_iterator const& x) const { return m_ptr < x.m_ptr; }
		bool operator > (vector_const_iterator const& x) const { return m_ptr > x.m_ptr; }
		bool operator <= ( vector_const_iterator const& x) const { return m_ptr <= x.m_ptr; }
		bool operator >=(vector_const_iterator const& x) const { return m_ptr >= x.m_ptr; }

		vector_const_iterator& operator++(void)
		{
			m_ptr++;
			return *this;
		}

		vector_const_iterator operator++(int)
		{
			vector_const_iterator temp(*this);
			++(*this);
			return temp;
		}

		vector_const_iterator& operator--(void)
		{
			m_ptr--;
			return *this;
		}

		vector_const_iterator operator--(int)
		{
			vector_const_iterator temp(*this);
			--(*this);
			return temp;
		}

		vector_const_iterator& operator+=(difference_type i)
		{
			m_ptr += i;
			return *this;
		}

		vector_const_iterator& operator-=(difference_type i)
		{
			m_ptr -= i;
			return *this;
		}

		vector_const_iterator operator+(difference_type i) const
		{
			return vector_const_iterator(m_ptr + i);
		}

		friend vector_const_iterator operator+(difference_type i,
				vector_const_iterator const& x)
		{
			return vector_const_iterator(x + i);
		}

		vector_const_iterator operator-(difference_type i) const
		{
			return vector_const_iterator(m_ptr - i);
		}

		difference_type operator-(vector_const_iterator const& x) const
		{
			return m_ptr - x.m_ptr;
		}
	private:
		pointer m_ptr;

	};
}

#endif
