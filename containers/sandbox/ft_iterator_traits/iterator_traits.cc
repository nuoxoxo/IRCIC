#ifndef __ITERATOR_TRAITS__
# define __ITERATOR_TRAITS__

/*
namespace std  {
	template <class T>
	struct	iterator_traits {
		typedef typename T::value_type		value_type;
		typedef typename T::difference_type	difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer		pointer;
		typedef typename T::reference		reference;
	};
}
*//* std::iterator_traits 
     is the type trait class that provides 
     uniform interface to the properties
     of LegacyIterator types. */

namespace	ft /*std*/
{

template<typename /*class*/ T>
class	iterator_traits
{
public:
	typedef	typename T::iterator_category	iterator_category;
	typedef	typename T::difference_type	difference_type;
	typedef	typename T::value_type		value_type;
	typedef	typename T::pointer		pointer;
	typedef	typename T::reference		reference;
};

}

#endif
