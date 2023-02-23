#include "iostream"
#include "string"

# define color_1 "\x1b[33m"
# define color_2 "\x1b[36m"
# define color_3 "\x1b[0m"
# define nl2 "\n\n"

class	Entity
{
public:
	std::string	Name;
	int		Size;

	explicit	Entity(const std::string & name) : Name(name), Size(-1) {}
	explicit	Entity(const int size) : Name("Unknown"), Size(size) {}
};


void	printer(const Entity &, const Entity &);

//	drive

int	main()
{
	std::cout << "- \n";

	//	test 1

	std::cout << color_2 "usual call: " nl2 color_1
	"Entity a(\"Monster\"); \n"
	"Entity b(96883); " color_3 nl2;

	Entity	a("Monster");
	Entity	b(196883);

	printer(a, b);

	//	test 2

	std::cout << color_2 "usual call: " nl2 color_1
	"Entity i = Entity(\"Monster\");\n"
	"Entity o = entity(96883); " color_3 nl2;

	Entity	i = Entity("Monster");
	Entity	o = Entity(196883);

	printer(i, o);

	//	explicit keyword : both test 3 & test 4 won't run as a result

/*
	//	test 3

	std::cout << color_2 "implicit construction: " nl2 color_1
	"Entity x = string(\"Monster\"); \n"
	"Entity y = 96883; " color_3 nl2;

	Entity	x = std::string("Monster"); // can't do: Entity	x = "Monster";
	Entity	y = 196883;
	
	printer(x, y);

	//	test 3

	std::cout <<
	color_2 "implicit conversion: " nl2
	color_1 "printer(std::string(\"Monster\"), 196883); " color_3 nl2;

	printer(std::string("Monster"), 196883);
	std::cin.get();
*/
}

void	printer(const Entity & e1, const Entity & e2)
{
	std::cout 
	<< "1. \nName: " << e1.Name << "\nSize: " << e1.Size << "\n"
	<< "2. \nName: " << e2.Name << "\nSize: " << e2.Size << nl2;
}
