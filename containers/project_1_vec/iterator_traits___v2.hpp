#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

# include "cstddef" // ptrdiff_t

namespace ft
{

	// 5 Iter categories :: defined for STL in file named : 
	// 	stl_iterator_base_types.hpp

	/**
	 * @defgroup iterator_tags Iterator Tags
	 * These are empty types, used to distinguish different iterators.  The
	 * distinction is not made by what they contain, but simply by what they
	 * are.  Different underlying algorithms can then be used based on the
	 * different operations supported by different iterator types.
	 */


	// Define iterators categories
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Define Iterator struct
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	// Default struct for iterator_traits
	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	// you'll also need vector-specific pointers for * and const *

	// define traits for pointer *
	template <class T>
	struct iterator_traits<T *>
	{
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef T *							pointer;
		typedef T &							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	// define traits for pointer *
	template <class T>
	struct iterator_traits<const T *>
	{
		typedef T							value_type;
		typedef ptrdiff_t					difference_type;
		typedef const T *					pointer;
		typedef const T &					reference;
		typedef random_access_iterator_tag	iterator_category;
	};
}

#endif
