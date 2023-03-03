/* 
 * < The C++ Standard Library - A Tutorial and Reference >
 * Nicolai M. Josuttis, Addison-Wesley, 1999
 *
 */

#include "iostream"
#include "limits"

namespace	MyLibrary
{
	template<class T>
	class	MyAllocator
	{
	public:
		// type definitions
		typedef T		value_type;
		typedef T *		pointer;
		typedef T &		reference;
		typedef const T *	const_pointer;
		typedef const T &	const_reference;
		typedef std::size_t	size_type;
		typedef std::ptrdiff_t	difference_type;


		// rebind allocator to type U
		templat <class U>
		class	rebind
		{
		public:
		   typedef MyAllocator<U>	other;
		};


		// return address of values
		pointer address (reference value) const
		{ return & value; }

		const_pointer address (const_reference value) const
		{
			return & value;
		}


		/* constructors and destructor
		 * - nothing to do because the allocator has no state
		 */

		MyAllocator() throw() {}
		MyAllocator(const MyAllocator&) throw() {}

		template<class U>
		MyAllocator (const MyAllocator<U> &) throw() {}
		~MyAllocator() throw() {}


		// return maximum number of elements that can be allocated
		size_type max_size () const throw()
		{ return std::numeric_limits<std::size_t>::max() / sizeof(T); }


		// allocate but don't initialize num elements of type T
		pointer	allocate (size_type num, const void * = 0)
		{
			// print message and allocate memory with global new
			std::cerr
			<< "allocate " << num << " element(s)"
			<< " of size " << sizeof(T) << std::endl;

			pointer	res = (pointer) (::operator new (num * sizeof(T)));
			std::cerr << " allocated at: " << (void *) res << std::endl;
			return (res);
		}


	};


	// return that all specializations of this allocator are interchangeable

	template<class T1, class T2>
	bool	operator == (const MyAllocator<T1> &, const MyAllocator<T2> &) throw() { return true; }

	template<class T1, class T2>
	bool	operator != (const MyAllocator<T1> &, const MyAllocator<T2> &) throw() { return false; }
}
