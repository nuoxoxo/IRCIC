int main(int c, char **v)
{
	int i = 0;
	while (++i < c) printf("%c", atoi(v[i]));
}
