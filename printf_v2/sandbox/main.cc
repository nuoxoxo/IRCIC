#include "iostream"

int	main()
{
	double	dub;
	int	num;
	{
		num = 1024;
		printf("The 1st number is %5d\n", num);

		num = 512;
		printf("The 2nd number is %5d\n", num);

		num = 256;
		printf("The number is %07d\n", num);
		printf("The number is %-7d\n", num);
	}

}
