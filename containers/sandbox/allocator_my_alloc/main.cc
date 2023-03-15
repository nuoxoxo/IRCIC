template <class T>
class	MyAllocator
{
public:
	using	value_type	T;
	using	size_type	size_t;
	using	pointer = T*;
	using	const_pointer = const T*;
	using	void_pointer = void*;
	using	const_void_pointer = const void*;
	using	difference_type = std::ptrdiff_t;

	MyAllocator() = default;
	~MyAllocator() = default;


	pointer	allocator (size_type size)
	{
		return
		(static_cast<pointer> (operator new (sizeof(T) * size)) );
	}


	pointer allocate(size_type size, const_void_pointer it)
	{
		return ( allocate(size) );
	}


	void	deallocate(pointer ptr, size_type size)
	{
		operator delete (ptr);
	}
};
