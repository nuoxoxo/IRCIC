#include "iterator" // iterator_tag
#include "cstddef"  // ptrdiff_t

class	Integers
{

public:
	struct	Iterator
	{
		using iterator_category	= std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type	= int;
		using pointer		= int *;
		using reference		= int &;

	};
	
};





