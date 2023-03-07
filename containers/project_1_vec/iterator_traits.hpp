#ifndef __ITERATOR_TRAITS_HPP__
# define __ITERATOR_TRAITS_HPP__

// # include "iterator" // iterator_tag /// seems omittable

# include "cstddef" // ptrdiff_t

namespace	ft
{
	// 5 Iter categories :: defined for STL in file named : 
	// 	stl_iterator_base_types.hpp

	/**
	 * 	iterator_tags Iterator Tags
	 * 
	 * These are empty types, used to distinguish different iterators.  The
	 * distinction is not made by what they contain, but simply by what they
	 * are.  Different underlying algorithms can then be used based on the
	 * different operations supported by different iterator types.
	 */

	///	Notes from fellow stud Twagger / Thomas
	// Iterator traits 
	// is a definition of member types for any iterator 
	// that let us get iterator types 
	// from a simple pointer to a certain type (T)
    // so it can be used properly with algorithms.

	///  Marking input iterators.
	struct input_iterator_tag {};


	///  Marking output iterators.
	struct output_iterator_tag {};


	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag {};


	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag {};


	/// Random-access iterators support a superset of bidirectional iterator
	/// operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	//	Define Iterator struct
	// We use this master template to get types
	// from the iterator type itself
	template<typename T>
	class	iterator_traits // Master template
	{
	public:
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::difference_type	difference_type;

		typedef	typename T::value_type	value_type;
		typedef typename T::reference	reference;

		typedef typename T::pointer	pointer;
	};


	// Iterator - as in vector<T>::iterator
	template<
		class T, class Category, 
		class Distance = std::ptrdiff_t, 
		class Reference = T &, class Pointer = T *
	>
	class	iterator
	{
	public:
		typedef Category	iterator_category;
		typedef Distance	difference_type;
		typedef Reference	reference;
		typedef Pointer		pointer;
		typedef	T		value_type;
	};


	// you'll also need vector-specific pointers for * and const *

	template<class T>
	class	iterator_traits<T *>
	{
	public:
		typedef std::random_access_iterator_tag	iterator_category;

		typedef ptrdiff_t	difference_type;
		typedef	T		value_type;
		typedef T		* pointer;
		typedef T		& reference;
	};

	template<class T>
	struct	iterator_traits<const T *>
	{
	public:
		typedef std::random_access_iterator_tag	iterator_category;

		typedef ptrdiff_t	difference_type;
		typedef T		value_type;
		typedef const T		* pointer;
		typedef const T		& reference;
		
	};

}

#endif
