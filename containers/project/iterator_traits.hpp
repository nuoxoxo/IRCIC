#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

# include "iterator" // iterator_tag
# include "cstddef" // ptrdiff_t

namespace	ft
{
	// 5 Iter categories
	// defined for STL in file named : stl_iterator_base_types.hpp

	struct	input_iterator_tag {};
	struct	output_iterator_tag {};
	struct	forward_iterator_tag : public input_iterator_tag {};
	struct	bidirectional_iterator_tag : public forward_iterator_tag {};
	struct	random_access_iterator_tag : public bidirectional_iterator_tag {};

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
