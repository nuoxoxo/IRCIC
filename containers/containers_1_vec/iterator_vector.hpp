#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

# include "iterator_traits.hpp"

namespace ft
{
	template<typename Iter_T>
	class	Iterator_Vector : public ft::Iter_T<ft::random_access_iterator_tag, Iter_T>
	{
		protected:
			Iter_T _current;

		public:
			// typedef Iter_T	iterator_type;
			// typedef typename ft::iterator_traits<Iter_T>::iterator_category iterator_category;
			// typedef typename ft::iterator_traits<Iter_T>::value_type	value_type;

			typedef typename ft::iterator_traits<Iter_T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter_T>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter_T>::reference			reference;

			Iterator_Vector() : _current() {}

			explicit Iterator_Vector(Iter_T x) : _current(x) {}

			Iterator_Vector(const Iterator_Vector &x) : _current(x._current) {}

			template<typename Iter> // Allow it to const_it conversion
			Iterator_Vector(const Iterator_Vector<Iter> &x) : _current(x.base()) {}

			Iterator_Vector	operator=(Iterator_Vector const &src)
			{
				if (*this == src)
					return *this;
				_current = src._current;
				return *this;
			}

			Iter_T base() const
			{
				return _current;
			}

			reference	operator*() const
			{
				Iter_T tmp = _current;
				return (*tmp);
			}

			pointer		operator->() const
			{
				return &(operator*());
			}

			Iterator_Vector	&operator++() // ++n
			{
				_current++;
				return *this;
			}

			Iterator_Vector	operator++(int) // n++
			{
				Iterator_Vector tmp(*this);
				_current++;
				return tmp;
			}

			Iterator_Vector	&operator--() // --n
			{
				_current--;
				return *this;
			}

			Iterator_Vector	operator--(int) // n--
			{
				Iterator_Vector tmp(*this);
				_current--;
				return tmp;
			}

			Iterator_Vector	operator+(difference_type _n) const
			{
				return Iterator_Vector(_current + _n);
			}

			Iterator_Vector	operator-(difference_type _n) const
			{
				return Iterator_Vector(_current - _n);
			}

			Iterator_Vector	&operator+=(difference_type _n)
			{
				_current += _n;
				return *this;
			}

			Iterator_Vector	&operator -=(difference_type _n)
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
	bool	operator==(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator!=(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator<(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<typename _IterL, typename _IterR>
	bool	operator>(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return rhs < lhs;
	}

	template<typename _IterL, typename _IterR>
	bool	operator<=(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return !(rhs < lhs);
	}

	template<typename _IterL, typename _IterR>
	bool	operator>=(const Iterator_Vector<_IterL>& lhs, const Iterator_Vector<_IterR>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename _Iter>
	Iterator_Vector<_Iter>	operator+(typename Iterator_Vector<_Iter>::difference_type _n, const Iterator_Vector<_Iter> &_x)
	{
		return Iterator_Vector<_Iter>(_x.base() + _n);
	}

	template<typename _IterL, typename _IterR>
	typename Iterator_Vector<_IterL>::difference_type	operator-(const Iterator_Vector<_IterL> &lhs, const Iterator_Vector<_IterR> &rhs)
	{
		return lhs.base() - rhs.base();
	}
}

#endif

