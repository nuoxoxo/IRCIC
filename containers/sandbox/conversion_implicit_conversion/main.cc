#include "iostream"
#include "string"

# define c1 "\x1b[33m"
# define c2 "\x1b[36m"
# define c3 "\x1b[0m"
# define nl2 "\n\n"

class	Entity
{
public:
	std::string	Name;
	int		Size;

	Entity(const std::string & name) : Name(name), Size(1) {}
	Entity(const int size) : Name("Unknown"), Size(size) {}
};

void	PrintEntityX2(const Entity & e1, const Entity & e2)
{
	std::cout 
	<< "Name: " << e1.Name << "\nSize: " << e1.Size << nl2
	<< "Name: " << e2.Name << "\nSize: " << e2.Size << nl2;
}

//	drive

int	main()
{
	std::cout << "\n- \n\n";
	//	test 1
	{
		std::cout << c2 "usual call: " nl2 c1
		"Entity a(\"Monster\"); \n"
		"Entity b(96883); " c3 nl2;

		Entity	a("Monster");
		Entity	b(196883);

		PrintEntityX2(a, b);
	}
	//	test 2
	{
		std::cout << c2 "usual call: " nl2 c1
		"Entity a = Entity(\"Monster\");\n"
		"Entity b = entity(96883); " c3 nl2;

		Entity	a = Entity("Monster");
		Entity	b = Entity(196883);

		PrintEntityX2(a, b);
	}
	//	test 3
	{
		std::cout << c2 "implicit construction: " nl2 c1
		"Entity a = string(\"Monster\"); \n"
		"Entity b = 96883; " c3 nl2;

		Entity	a = std::string("Monster"); // can't do: Entity	x = "Monster";
		Entity	b = 196883;
		
		PrintEntityX2(a, b);
	}
	//	test 3
	{
		std::cout <<
		c2 "implicit conversion: " nl2
		c1 "PrintEntityX2(std::string(\"Monster\"), 196883); " c3 nl2;

		PrintEntityX2(std::string("Monster"), 196883);
	}
	// std::cin.get();
}
