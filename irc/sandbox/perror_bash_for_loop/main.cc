#include "iostream"
// #include "cstdlib"

int	main()
{
	srand(time(0));
	if (rand() % 2)
	{
		perror("funny & odd");
	}
}

