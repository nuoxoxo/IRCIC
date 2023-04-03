#include "stdio.h"
#include "string.h"

int	main(int argc, char **v)
{
	if (argc ^ 2 || !strlen(v[1]))
		return 0;

	int	res;
	int	A; // how many Aces
	int	i;
	char	c;

	res = 0;
	A = 0;
	i = -1;
	while (++i < (int) strlen(v[1]))	
	{
		c = v[1][i];
		if (c == 'J' || c == 'D' || c == 'K' || c == 'T')
			res += 10;
		else if (c <= '9' && c > '1')
			res += c - '0';
		else if (c == 'A')
			++A;
		else
			return 0;
	}
	if (!A)
	{
		if (res ^ 21)
			return (printf("%d\n", res), 0);
		return (printf("Blackjack!\n"), 0);

	}
	while (A)
	{
		//printf("%d, %d\n", A, res);

		if (res + 11 > 20)
			++res;
		else
			res += 11;
		--A;
	}
	if (res ^ 21)
		return (printf("%d\n", res), 0);
	printf("Blackjack!\n");
}

