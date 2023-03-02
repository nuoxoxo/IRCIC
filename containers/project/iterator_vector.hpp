#ifndef __ITERATOR_FOR_VECTOR_HPP__
# define __ITERATOR_FOR_VECTOR_HPP__

# include "iterator_traits.hpp"

namespace	ft
{
	// Default struct for iterator_traits

	template< typename Iter_T >
	class	Iterator_Vector : public ft::iterator< Iter_T, ft::random_access_iterator_tag >
	{

	protected:
		Iter_T	m_current;

	public:
		typedef typename ft::iterator_traits<Iter_T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Iter_T>::reference		reference;
		typedef typename ft::iterator_traits<Iter_T>::pointer		pointer;
	};


	// canon

	explicit Iterator_Vector(Iter_T it) : m_current(it) {}

	Iterator_Vector() : m_current() {}

	Iterator_Vector(const Iterator_Vector & it) : m_current(it.m_current) {}

	template<typename Iter>	// const iterator conversion
	Iterator_Vector(const Iterator_Vector<Iter> & it) : m_current(it.base()) {}


	// base (?)
	Iter_T base() const { return (m_current); }


	// assignment

	Iterator_Vector	operator = (Iterator_Vector const & it)
	{
		if (*this == it) return (*this);
		m_current = it._current;
		return (*this);
	}


	// random access

	reference operator [] (difference_type const & _steps_) cons
	{ return (*(m_current + _steps_)); }


	// ptr & dereferencer

	reference	operator * () const { return (*m_current); }
	pointer		operator -> () const { return (m_current); }


	// ++  +=  --  -=

	Iterator_Vector	& operator ++ () { m_current++; return (*this); }
	Iterator_Vector	& operator -- () { m_current--; return (*this); }

	Iterator_Vector	operator ++ ()
	{
		Iterator_Vector		dummy(*this);

		m_current++;
		return (dummy);
	}

	Iterator_Vector	operator -- ()
	{
		Iterator_Vector		dummy(*this);

		m_current--;
		return (dummy);
	}












}

#endif
