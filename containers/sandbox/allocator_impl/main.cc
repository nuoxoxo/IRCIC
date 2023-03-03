#include "iostream"
#include "MyAllocator.hh"
#include "vector"

int	main()
{
	// create a vector, using MyAlloc<> as allocator
	std::vector<int, MyLibrary::MyAllocator<int>>	v;


	// insert elements
	// - causes reallocations
	v.push_back(42);
	v.push_back(21);
	v.push_back(1024);
	v.push_back(64);
	v.push_back(196883);
	v.push_back((int) 1e9);
}
