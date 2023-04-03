int	main(int c, char **v)
{
	int	i = 0;
	while (++i < c)
		printf("%c", (char) atoi(v[i]));
}
