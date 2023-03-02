#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

# include "iterator" // iterator_tag
# include "cstddef" // ptrdiff_t

namespace	ft
{
	// 5 Iter categories defined for STL in file named : 
	// 	stl_iterator_base_types.hpp

	/**
	 * @defgroup iterator_tags Iterator Tags
	 * These are empty types, used to distinguish different iterators.  The
	 * distinction is not made by what they contain, but simply by what they
	 * are.  Different underlying algorithms can then be used based on the
	 * different operations supported by different iterator types.
	 */

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

	





}

#endif
