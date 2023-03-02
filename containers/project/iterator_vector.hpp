#ifndef __ITERATOR_FOR_VECTOR_HPP__
# define __ITERATOR_FOR_VECTOR_HPP__

# include "iterator_traits.hpp"

namespace	ft
{
	// Default struct for iterator_traits
	template< typename Iterator_T >
	class	Iterator_Vector : public ft::iterator< Iterator_T, ft::random_access_iterator_tag >
	{

	protected:
		Iterator_T	m_current;

	public:
		typedef typename ft::iterator_traits<Iterator_T>::difference_type  difference_type;
		typedef typename ft::iterator_traits<Iterator_T>::reference	reference;
		typedef typename ft::iterator_traits<Iterator_T>::pointer	pointer;
	};



}

#endif
