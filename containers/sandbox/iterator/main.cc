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

		Iterator begin()
		{ return Iterator( & m_data[0] ); }
		
		Iterator end()
		{ return Iterator( & m_data[200] ); } // 1st invalid memory zone

		reference operator * () const { return (*m_ptr); }
		pointer operator -> () { return (m_ptr); }

		// pre ++
		Iterator & operator ++ () { m_ptr++; return (*this); }

		// post ++
		Iterator operator ++ (int)
		{ Iterator tmp = *this; ++(*this); return (tmp); }

		friend bool operator == (const Iterator & l, const Iterator & r)
		{ return (l.m_ptr == r.m_ptr); }

		friend bool operator != (const Iterator & l, const Iterator & r)
		{ return (l.m_ptr != r.m_ptr); }



	};
	
};





