#include "iostream"
#include "string"
#include "Fmt.hpp"


class	Entity
{
public:
	std::string	Name;
	int		Size;

	explicit	Entity(const std::string & name) : Name(name), Size(1) {}
	explicit	Entity(const int size) : Name("Unknown"), Size(size) {}
};


void	printer(const Entity &, const Entity &);

//	drive

int	main()
{
	std::cout << "- \n";

	//	test 1
	{
		std::cout << c2 "usual call: " nl2 c1
		"Entity a(\"Monster\"); \n"
		"Entity b(96883); " c3 nl2;

		Entity	a("Monster");
		Entity	b(196883);

		printer(a, b);
	}
	//	test 2
	{
		std::cout << c2 "usual call: " nl2 c1
		"Entity a = Entity(\"Monster\");\n"
		"Entity b = entity(96883); " c3 nl2;

		Entity	a = Entity("Monster");
		Entity	b = Entity(196883);

		printer(a, b);
	}
	//	explicit keyword : both test 3 & test 4 won't run as a result

/*
	//	test 3
	{
		std::cout << c2 "implicit construction: " nl2 c1
		"Entity a = string(\"Monster\"); \n"
		"Entity b = 96883; " c3 nl2;

		Entity	a = std::string("Monster"); // can't do: Entity	x = "Monster";
		Entity	b = 196883;
		
		printer(x, y);
	}
	//	test 3
	{
		std::cout <<
		c2 "implicit conversion: " nl2
		c1 "printer(std::string(\"Monster\"), 196883); " c3 nl2;

		printer(std::string("Monster"), 196883);
	}
	//std::cin.get();
*/
}

void	printer(const Entity & e1, const Entity & e2)
{
	std::cout 
	<< "Name: " << e1.Name << "\nSize: " << e1.Size << nl2
	<< "Name: " << e2.Name << "\nSize: " << e2.Size << nl2;
}
