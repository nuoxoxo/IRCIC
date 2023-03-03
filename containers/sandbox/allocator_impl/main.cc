#include "iostream"
#include "MyAllocator.hh"
#include "vector"

void	push() { std::cout << CYAN "(pushed)" RESET "\n-\n\n"; }

template<typename T, typename... Types>
void	push(T n1, Types... n2)
{
	std::cout << n1 << nl ;
	push(n2...);
}
int	main()
{
	/* use	MyLibrary::MyAlloc< T >
	 * as allocator to create a vector	*/

	std::vector<int, MyLibrary::MyAllocator<int>>	v;


	// insert elements  -  causes reallocations

	push(42, 41, 43);
	v.push_back(42);
	v.push_back(41);
	v.push_back(43);

	push(1 << 7, 1 << 8, 1 << 9, 1 << 10);	v.push_back(1 << 7);
	v.push_back(1 << 8);
	v.push_back(1 << 9);
	v.push_back(1 << 10);

	push(1 << 6, 197883);
	v.push_back(64);
	v.push_back(196883);

	push((int) 1e9);
	v.push_back((int) 1e9);


	// pop back  -  size allocated would stays the same

	std::cout << "Size before popping: " << v.size() << nl2;
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();

	std::cout << "Size after popping 4 elems: " << v.size() << nl2;
	v.pop_back();
	v.pop_back();

	std::cout << "Size after popping 2 elems: " << v.size() << nl2;

}
