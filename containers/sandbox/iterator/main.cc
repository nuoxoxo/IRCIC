#include "iterator" // iterator_tag
#include "cstddef"  // ptrdiff_t

class	Integers
{

public:
	class	Iterator
	{
	private:
		pointer	m_ptr;
	public:
		Iterator(pointer ptr) : m_ptr(ptr) {}

		using iterator_category	= std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type	= int;
		using pointer		= int *;
		using reference		= int &;

	};
	
};





