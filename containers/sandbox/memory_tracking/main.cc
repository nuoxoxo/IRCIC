#include "iostream"
#include "../Fmt.hpp"


static int i = 0;

void	*operator new(size_t size) throw(std::bad_alloc)
{
	std::cout << "\n" << CYAN << __FUNCTION__ << " called \n" RESET;
	std::cout << "Allocating " << size << " bytes ";
	std::cout << "[line " << ++i << "] \n";
	return (malloc(size));
}

void	operator delete (void *p, size_t size) // no overloading
{
	std::cout << "\n" << CYAN << __FUNCTION__ << " called \n" RESET;
	std::cout << "Freeing " << size << " bytes ";
	std::cout << "signature: .# [line " << ++i << "] \n";
	free(p);
}

void	operator delete(void * p) throw()
{
	std::cout << "\n" << CYAN << __FUNCTION__ << " called \n" RESET;
	std::cout << "signature: .@ [line " << ++i << "] \n";
	free(p);
}

struct	Object { int x, y, z; };

int	main()
{
	Object		*obj = new Object;
	std::string	s = "1234567890123456abcdef"; // no alloc
	std::string	t = "12345678901234567890123";

	std::cout << "\nno alloc length: " << s.length();
	std::cout << "\nbreakpoint length: " << t.length() << "\n";

	delete obj;

}
