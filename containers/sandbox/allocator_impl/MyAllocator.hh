/* 
 * < The C++ Standard Library - A Tutorial and Reference >
 * Nicolai M. Josuttis, Addison-Wesley, 1999
 *
 */

#ifndef __MYALLOCATOR_HH__
# define __MYALLOCATOR_HH__
# pragma once

# include "iostream"
# include "limits"

# define CYAN	"\033[0;36m"
# define YELLO	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define CYAN	"\033[0;36m"
# define RESET	"\033[0;0m"
# define MSGALLOC GREEN " allocated " RESET
# define MSGDEALLOC YELLO " deallocated " RESET
# define nl2 "\n\n"
# define nl "\n"

namespace	MyLibrary
{
	template<class T>
	class	MyAllocator
	{
	public:
		// type definitions
		typedef T		value_type;
		typedef std::size_t	size_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T *		pointer;
		typedef T &		reference;
		typedef const T *	const_pointer;
		typedef const T &	const_reference;


		// rebind allocator to type U
		template<class U>
		class	rebind
		{
		public:
			typedef MyAllocator<U>	other;
		};


		/* constructors and destructor
		 * - nothing to do because the allocator has no state
		 */

		MyAllocator() throw() {}
		MyAllocator(const MyAllocator &) throw() {}

		template<class U>
		MyAllocator (const MyAllocator<U> &) throw() {}

		~MyAllocator() throw() {}


		// return address of values
		pointer address (reference val) const { return & val; }

		const_pointer address (const_reference val) const { return & val; }



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

			std::cerr << MSGALLOC "at: " << (void *) res << nl2;

			return (res);
		}


		// initialize elements of allocated storage p with value value
		void	construct (pointer p, const T & value) { new((void *) p) T(value); }  // initialize memory with placement new


		// destroy elements of initialized storage p
		void	destroy (pointer p) { p->~T(); } // destroy objects by calling their destructor


		// deallocate storage p of deleted elements
		void	deallocate (pointer p, size_type num) //deallocate memory with global delete
		{
			std::cerr
			<< "deallocate " << num << " element(s)"
			<< " of size " << sizeof(T) << std::endl
			<< MSGDEALLOC "at: " << (void*)p << nl2;

			::operator delete((void*)p); // del.
		}


	};


	// return that all specializations of this allocator are interchangeable

	template<class T1, class T2>
	bool	operator == (const MyAllocator<T1> &, const MyAllocator<T2> &) throw() { return true; }

	template<class T1, class T2>
	bool	operator != (const MyAllocator<T1> &, const MyAllocator<T2> &) throw() { return false; }
}

#endif
