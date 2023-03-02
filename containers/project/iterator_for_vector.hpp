#ifndef __ITERATOR_FOR_VECTOR_HPP__
# define __ITERATOR_FOR_VECTOR_HPP__

# include "iterator_traits.hpp"

namespace	ft
{
	// Default struct for iterator_traits
	template<typename T>
	class	iterator_traits
	{
	public:
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::difference_type	difference_type;
		typedef	typename T::value_type	value_type;
		typedef typename T::pointer	pointer;
		typedef typename T::reference	reference;
	};


	// Iterator - as in vector<T>::iterator
	template<class T, class Category, class Distance = std::ptrdiff_t, 
		class Reference = T &, class Pointer = T *>
	class	iterator
	{
	public:
		typedef	T		value_type;
		typedef Category	iterator_category;
		typedef Distance	difference_type;
		typedef Reference	reference;
		typedef Pointer		pointer;
	};


	// you'll also need vector-specific pointers for * and const *

	template<class T>
	class	iterator_traits<T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef ptrdiff_t			difference_type;
		typedef	T				value_type;
		typedef T *				pointer;
		typedef T &				reference;
	}

	template<class T>
	struct	iterator_traits<const T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef ptrdiff_t			difference_type;
		typedef const T *			pointer;
		typedef const T &			reference;
		typedef T				value_type;
	};



}

#endif
