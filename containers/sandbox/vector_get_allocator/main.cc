#include "iostream"
#include "vector"

#define SIZE 5

using	namespace std;

int main ()
{
	std::vector<int> v;
	int	*dummy;
	int	i;

	// allocate an array with space for SIZE elements using vector's allocator:

	dummy = v.get_allocator().allocate(SIZE);

	// construct values in-place
	i = -1;
	while (++i < SIZE)
		v.get_allocator().construct(& dummy[i], SIZE - i + 41);


	// print
	cout << "The allocated array contains: \n";
	i = -1;
	while (++i < SIZE)
		std::cout << dummy[i] << "\n";


	// destroy and deallocate:
	i = -1;
	while (++i < SIZE)
		v.get_allocator().destroy(& dummy[i]);

	v.get_allocator().deallocate(dummy, SIZE);
}
