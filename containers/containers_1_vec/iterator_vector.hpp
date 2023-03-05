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
			Iterator _current;

		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			VectorIterator() : _current() {}

			explicit VectorIterator(Iterator x) : _current(x) {}

			VectorIterator(const VectorIterator &x) : _current(x._current) {}

			template<typename Iter> // Allow it to const_it conversion
			VectorIterator(const VectorIterator<Iter> &x) : _current(x.base()) {}

			VectorIterator	operator=(VectorIterator const &src)
			{
				if (*this == src)
					return *this;
				_current = src._current;
				return *this;
			}

			iterator_type base() const
			{
				return _current;
			}

			reference	operator*() const
			{
				Iterator tmp = _current;
				return (*tmp);
			}

			pointer		operator->() const
			{
				return &(operator*());
			}

			VectorIterator	&operator++() // ++n
			{
				_current++;
				return *this;
			}

			VectorIterator	operator++(int) // n++
			{
				VectorIterator tmp(*this);
				_current++;
				return tmp;
			}

			VectorIterator	&operator--() // --n
			{
				_current--;
				return *this;
			}

			VectorIterator	operator--(int) // n--
			{
				VectorIterator tmp(*this);
				_current--;
				return tmp;
			}

			VectorIterator	operator+(difference_type _n) const
			{
				return VectorIterator(_current + _n);
			}

			VectorIterator	operator-(difference_type _n) const
			{
				return VectorIterator(_current - _n);
			}

			VectorIterator	&operator+=(difference_type _n)
			{
				_current += _n;
				return *this;
			}

			VectorIterator	&operator -=(difference_type _n)
			{
				_current -= _n;
				return *this;
			}

			reference	operator[](difference_type const &_n) const
			{
				return *(_current + _n);
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
