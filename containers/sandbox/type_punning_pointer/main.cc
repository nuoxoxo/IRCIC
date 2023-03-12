#include "iostream"

#define C "\033[0;32m"
// #define C "\033[0;36m"
#define R "\033[0m"

static int i = 0;

void	header (std::string s) {
	std::cout << C "(" << ++i << ") " << s << " \n\n" R;
}

struct	Bocal
{
	int x, y, z, a, b, c;
};

int	main()
{
	header("struct treated as an array");
	{
		Bocal	b = { 10, 42 };
		int	*test = (int *) & b;
		int	i = -1;

		while (++i < 3) {
			std::cout << test[i] << (i==2? "\n\n": " ");
		}
	}
	header("try accessing [5]");
	{
		Bocal	b = { 2, 16, 21, 32, 42 };

		int	test = ((int *) & b)[4];
		int	test2 = *(int *)((int *) & b + 4);
		int	test3 = *(int *)((char *) & b + 16);
		int	test4 = *(int *)((float *) & b + 4);
		int	test5 = *(int *)((double *) & b + 2);
		int	test6 = *(int *)((unsigned int *) & b + 2);

		static int i = 0;

		std::cout << i++ << ": " << test << std::endl;
		std::cout << i++ << ": " << test2 << std::endl;
		std::cout << i++ << ": " << test3 << std::endl;
		std::cout << i++ << ": " << test4 << std::endl;
		std::cout << i++ << ": " << test5 << std::endl;
		std::cout << i++ << ": " << test5 << std::endl;

		std::cout << i++ << ": " << ((int *) & b)[5] << std::endl;

		std::cout << std::endl;
	}

}


