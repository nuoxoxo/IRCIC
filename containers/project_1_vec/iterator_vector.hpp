#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

#include "iterator_traits.hpp"

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class VectorIterator : public ft::iterator<ft::random_access_iterator_tag, Iterator>
	{
		protected:
			Iterator m_current;

		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			VectorIterator() : m_current() {}

			explicit VectorIterator(Iterator x) : m_current(x) {}

			VectorIterator(const VectorIterator &x) : m_current(x.m_current) {}

			template<typename Iter> // Allow it to const_it conversion
			VectorIterator(const VectorIterator<Iter> &x) : m_current(x.base()) {}

			VectorIterator	operator=(VectorIterator const &src)
			{
				if (*this == src)
					return *this;
				m_current = src.m_current;
				return *this;
			}

			iterator_type base() const
			{
				return m_current;
			}

			reference	operator*() const
			{
				Iterator tmp = m_current;
				return (*tmp);
			}

			pointer		operator->() const
			{
				return &(operator*());
			}

			VectorIterator	&operator++() // ++n
			{
				m_current++;
				return *this;
			}

			VectorIterator	operator++(int) // n++
			{
				VectorIterator tmp(*this);
				m_current++;
				return tmp;
			}

			VectorIterator	&operator--() // --n
			{
				m_current--;
				return *this;
			}

			VectorIterator	operator--(int) // n--
			{
				VectorIterator tmp(*this);
				m_current--;
				return tmp;
			}

			VectorIterator	operator+(difference_type _n) const
			{
				return VectorIterator(m_current + _n);
			}

			VectorIterator	operator-(difference_type _n) const
			{
				return VectorIterator(m_current - _n);
			}

			VectorIterator	&operator+=(difference_type _n)
			{
				m_current += _n;
				return *this;
			}

			VectorIterator	&operator -=(difference_type _n)
			{
				m_current -= _n;
				return *this;
			}

			reference	operator[](difference_type const &_n) const
			{
				return *(m_current + _n);
			}
	};

	template<typename _IterL, typename _IterR>
	bool	operator==(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator!=(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator<(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator>(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return rhs < lhs;
	}

	template<typename _IterL, typename _IterR>
	bool	operator<=(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename _IterL, typename _IterR>
	bool	operator>=(const VectorIterator<_IterL>& lhs, const VectorIterator<_IterR>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename _Iter>
	VectorIterator<_Iter>	operator+(typename VectorIterator<_Iter>::difference_type _n, const VectorIterator<_Iter> &_x)
	{
		return VectorIterator<_Iter>(_x.base() + _n);
	}

	template<typename _IterL, typename _IterR>
	typename VectorIterator<_IterL>::difference_type	operator-(const VectorIterator<_IterL> &lhs, const VectorIterator<_IterR> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}

#endif
