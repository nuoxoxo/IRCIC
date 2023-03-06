#ifndef __ITERATOR_REVERSE_ITERATOR_HPP__
# define __ITERATOR_REVERSE_ITERATOR_HPP__

# include "iterator_traits.hpp"

namespace ft
{
	template<typename Iterator>
	class reverse_iterator
	{

	protected:
		Iterator m_current;

	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Iterator>::value_type	value_type;
		typedef typename ft::iterator_traits<Iterator>::pointer		pointer;
		typedef typename ft::iterator_traits<Iterator>::reference	reference;

		explicit reverse_iterator(Iterator x) : m_current(x) {}

		reverse_iterator() : m_current() {}	
		reverse_iterator(const reverse_iterator & it) : m_current(it.m_current) {}

		template<typename Iter> // .. convert to const_iter
		reverse_iterator(const reverse_iterator<Iter> & it) : m_current(it.base()) {}

		reverse_iterator & operator = (reverse_iterator const & it)
		{
			if (*this != it)
				m_current = it.m_current;
			return (*this);
		}

		iterator_type base() const
		{
			return m_current;
		}

		reference operator * () const
		{
			Iterator tmp = m_current;

			return (*(--tmp));
		}

		pointer	operator -> () const
		{
			return &(operator*());
		}

		reverse_iterator & operator ++ ()
		{
			m_current--;

			return (*this);
		}

		reverse_iterator operator ++ (int)
		{
			reverse_iterator tmp(*this);
			m_current--;

			return (tmp);
		}

		reverse_iterator & operator -- ()
		{
			m_current++;

			return (*this);
		}

		reverse_iterator operator -- (int)
		{
			reverse_iterator tmp(*this);
			m_current++;

			return tmp;
		}

		reverse_iterator operator + (difference_type steps) const
		{
			return (reverse_iterator(m_current - steps));
		}

		reverse_iterator operator - (difference_type steps) const
		{
			return (reverse_iterator(m_current + steps));
		}

		reverse_iterator & operator += ( difference_type steps )
		{
			m_current -= steps;

			return (*this);
		}

		reverse_iterator & operator -= (difference_type steps)
		{
			m_current += steps;

			return (*this);
		}

		reference operator [] (difference_type steps) const
		{
			return (*(m_current - steps - 1));
		}
	};

	template<typename L, typename R>
	bool	operator == (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (l.base() == r.base());
	}

	template<typename L, typename R>
	bool	operator != (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (!(l.base() == r.base()));
	}

	template<typename L, typename R>
	bool	operator < (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (r.base() < l.base());
	}

	template<typename L, typename R>
	bool	operator > (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (r < l);
	}

	template<typename L, typename R>
	bool	operator <= (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (!(r < l));
	}

	template<typename L, typename R>
	bool	operator >= (
		const reverse_iterator<L> & l,
		const reverse_iterator<R> & r
	)
	{
		return (!(l < r));
	}

	template<typename Iter>
	reverse_iterator<Iter> operator + (
		typename reverse_iterator<Iter>::difference_type steps, 
		const reverse_iterator<Iter> &it
	)
	{
		return (reverse_iterator<Iter>(it.base() - steps));
	}

	template<typename L, typename R>
	typename reverse_iterator<L>::difference_type operator - (
		const reverse_iterator<L> & l, 
		const reverse_iterator<R> & r
	)
	{
		return (r.base() - l.base());
	}
}

#endif
