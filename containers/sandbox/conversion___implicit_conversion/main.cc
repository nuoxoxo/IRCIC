#include "iostream"
#include "string"

# define _c1	"\x1b[33m"
# define _c2	"\x1b[36m"
# define _r	"\x1b[0m"
# define nl2	"\n\n"

class	Entity
{
	public:
		std::string	Name;
		int		Size;

		Entity(const std::string & name)
			: Name(name), Size(-1) {}
		Entity(const int size)
			: Name("Unknown"), Size(size) {}
};

void	printer(const Entity & e1, const Entity & e2)
{
	std::cout 
	<< "1. \nName: " << e1.Name << "\nSize: " << e1.Size << "\n"
	<< "2. \nName: " << e2.Name << "\nSize: " << e2.Size << nl2;
}

//	drive

int	main()
{
	std::cout << "- \n";

	//	test 1

	std::cout << _c2 "usual call: " nl2 _c1
	"Entity a(\"Monster\"); \n"
	"Entity b(96883); " _r nl2;

	Entity	a("Monster");
	Entity	b(196883);

	printer(a, b);

	//	test 2

	std::cout << _c2 "usual call: " nl2 _c1
	"Entity i = Entity(\"Monster\");\n"
	"Entity o = entity(96883); " _r nl2;

	Entity	i = Entity("Monster");
	Entity	o = Entity(196883);

	printer(i, o);

	//	test 3

	std::cout << _c2 "implicit construction: " nl2 _c1
	"Entity x = string(\"Monster\"); \n"
	"Entity y = 96883; " _r nl2;

	Entity	x = std::string("Monster"); // can't do: Entity	x = "Monster";
	Entity	y = 196883;
	
	printer(x, y);

	//	test 3

	std::cout <<
	_c2 "implicit conversion: " nl2
	_c1 "printer(std::string(\"Monster\"), 196883); " _r nl2;

	printer(std::string("Monster"), 196883);

	std::cin.get();
}
