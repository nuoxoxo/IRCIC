#include "iostream"
#include "RPN.hpp"

// drive

int	main(int c, char **v)
{
	if (c == 2)
	{
		test(v[1], "", true);
		return 0;
	}

	
	test("8 9 * 9 - 9 - 9 - 4 - 1 +", "42");
	test("7 7 * 7 -", "42");

	test("(1 + 1)", Error);
	test("10 6 9 3 + -11 * / * 17 + 5 +", "13"); // gfg
	test("1 + 0 6 9 3 + -11 * / * 17 + 5 +", Error);

	test("3 4 +", "7");
	test("3 5 6 + *", "33");
	test("3 10 5 + *", "5");
	test("12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2 -", "42");
	test("99 3 -4 + 2 - 6 + -2 +", "-3");
	test("123 + -2 3 * 7 + -4 +", "-13");
	test("4 12 -764 + 23 * 23 1 -", "2");
	test("3 -4 5 + -", Error);
	
}


