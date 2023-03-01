#include "iostream"

class	ClassA
{

public:
	struct	constructor_1st{};
	struct	constructor_2nd{};

	explicit	ClassA(constructor_1st);
	explicit	ClassA(constructor_2nd);
};

int	main()
{

	ClassA	x((ClassA::constructor_1st())); // 
	ClassA	y(ClassA::constructor_2nd{}); // {} . uniform initialization

}

