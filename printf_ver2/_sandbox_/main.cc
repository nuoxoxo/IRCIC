#include "iostream"

int	main()
{
	double	pos, neg;
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

	{
		// usage of all 3 flags "# +" 
		//  :: placed before field minimum width specifier

		pos = 512.196883;
		neg = -512.196883;

		// the # flag
		//  Adds a prefix to the output of a floating-point value.
		//  The prefix depends on the type of the value,
		//  and the format specifier used as well.
		//
		// eg.
		//  The prefix for a floating-point value is the decimal point.
		//  The 15.2 field minimum width specifier specifies 15 chars,
		//  with 2 digits after the decimal point. 

		printf("('#') The 1st number is %#15.2f\n", pos);
		printf("('#') The 1st number is %#15.2f\n", neg);

		// the + flag
		//  Adds a sign (+ or -) to a signed value, 
		//  regardless of whether the value is pos + or neg -
		//
		// eg.
		//  The 15.2 field minimum width specifier specifies 15 chars,
		//  with 2 digits after the decimal point.

		printf("('+') The 2nd number is %+15.2f\n", pos);
		printf("('+') The 2nd number is %+15.2f\n", neg);

		// the ` ` (space) flag
		//  Adds a ' ' before a positive value if the value is signed
		// 
		// eg.
		//  The 15.2 field minimum width specifier specifies 15 chars,
		//  with 2 digits after the decimal point.

		printf("(' ') The 3rd number is % 15.2f\n", pos);
		printf("(' ') The 3rd number is % 15.2f\n", neg);
	}
}
