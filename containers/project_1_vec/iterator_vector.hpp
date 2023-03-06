#ifndef __ITERATOR_VECTOR_HPP__
# define __ITERATOR_VECTOR_HPP__

#include "iterator_traits.hpp"

#include "iterator_traits.hpp"

namespace ft
{
	template<typename Iterator>
	class VectorIterator : public ft::iterator<ft::random_access_iterator_tag, Iterator>
	{
	protected:
		Iterator	m_current;

	public:
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;

		typedef typename ft::iterator_traits<Iterator>::value_type	value_type;
		typedef typename ft::iterator_traits<Iterator>::reference	reference;
		typedef typename ft::iterator_traits<Iterator>::pointer		pointer;

		typedef Iterator	iterator_type;


		// canon

		explicit VectorIterator(Iterator x) : m_current(x) {}

		VectorIterator() : m_current() {}
		VectorIterator(const VectorIterator &x) : m_current(x.m_current) {}

		template<typename Iter>
		VectorIterator(const VectorIterator<Iter> &x) : m_current(x.base()) {}


		// operators

		VectorIterator operator = (VectorIterator const & it)
		{
			if (*this != it)
				m_current = it.m_current;

			return (*this);
		}

		iterator_type base() const
		{
			return (m_current);
		}

		reference operator * () const
		{
			Iterator	tmp = m_current;

			return (*tmp);
		}

		pointer	 operator->() const
		{
			return (&(operator * ()));
		}

		VectorIterator & operator  ++ () // ++n
		{
			m_current++;

			return (*this);
		}

		VectorIterator operator ++ (int) // n++
		{
			VectorIterator	tmp(*this);
			m_current++;

			return tmp;
		}

		VectorIterator & operator  -- () // --n
		{
			m_current--;

			return *this;
		}

		VectorIterator operator -- (int) // n--
		{
			VectorIterator	tmp(*this);
			m_current--;

			return tmp;
		}

		VectorIterator operator + (difference_type steps) const
		{
			return VectorIterator(m_current + steps);
		}

		VectorIterator operator - (difference_type steps) const
		{
			return VectorIterator(m_current - steps);
		}

		VectorIterator & operator += (difference_type steps)
		{
			m_current += steps;
			return (*this);
		}

		VectorIterator & operator -= (difference_type steps)
		{
			m_current -= steps;
			return (*this);
		}

		reference operator [] (difference_type const & steps) const
		{
			return (*(m_current + steps));
		}
	};

	template<typename L, typename R>
	bool operator == (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return l.base() == r.base();
	}

	template<typename L, typename R>
	bool operator != (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return l.base() != r.base();
	}

	template<typename L, typename R>
	bool operator < (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return (l.base() < r.base());
	}

	template<typename L, typename R>
	bool operator > (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return (r < l);
	}

	template<typename L, typename R>
	bool operator <= (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return (!(r < l));
	}

	template<typename L, typename R>
	bool operator >= (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return (!(l < r));
	}

	template<typename _Iter>
	VectorIterator<_Iter> operator + (
		typename VectorIterator<_Iter>::difference_type steps, 
		const VectorIterator<_Iter> & it
	)
	{
		return (VectorIterator<_Iter>(it.base() + steps));
	}

	template<typename L, typename R>
	typename VectorIterator<L>::difference_type operator - (
		const VectorIterator<L> & l,
		const VectorIterator<R> & r
	)
	{
		return (l.base() - r.base());
	}
}

#endif
