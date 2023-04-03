#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	fill_grid(char **grid, int size, const char *s, char c);
char	*fill_row(char *row, char const *s, int index, int offset);
int		get_offset(char const *s, int index, char c);
int		get_size(char const *s, char c);
char	**ft_split(char const *, char);

int	main(int c, char **v)
{
	size_t		len, max = 0;
	size_t		trail;
//	char		*tok;
	char		**G;
	int	i;

	if (c ^ 2)
		return 0;

	char	*s = v[1];

	G = ft_split(s, ' ');

	i = -1;
	while (G[++i])
	{
		len = strlen(G[i]);
		max = len > max ? len : max;

		// printf("%zu\n", len);
	}

	max += 5;

	char	shangxia[max];

	i = -1;
	while (++i < (int) max) shangxia[i] = (i ^ (max - 1)) ? '*' : '\0';

	printf("%s\n", shangxia);
	i = -1;
	while (G[++i])
	{
		printf("* %s", G[i]);
		trail = max - strlen(G[i]) - 4;
		while (--trail > 0)	printf(" ");
		printf(" *\n");
	}
	printf("%s\n", shangxia);

}

char	**ft_split(char const *s, char c)
{
	char	**grid;
	int		size;

	size = get_size(s, c);
	grid = (char **) malloc(sizeof(char *) * (size + 1));
	if (!grid)
		return (NULL);
	fill_grid(grid, size, s, c);
	return (grid);
}

void	fill_grid(char **grid, int size, const char *s, char c)
{
	int		offset;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < size)
	{
		while (s[++j])
		{
			if (s[j] && s[j] != c)
			{
				offset = get_offset(s, j, c);
				grid[i] = fill_row(grid[i], s, j, offset);
				j += offset;
				break ;
			}
		}
	}
	grid[i] = 0;
}

char	*fill_row(char *row, char const *s, int index, int offset)
{
	int		i;

	row = (char *) malloc(sizeof(char) * (offset + 1));
	if (!row)
		return (NULL);
	i = -1;
	while (++i < offset)
		row[i] = s[index + i];
	row[i] = 0;
	return (row);
}

int	get_offset(char const *s, int index, char c)
{
	int		size;
	int		i;

	size = 0;
	i = index - 1;
	while (s[++i] && s[i] != c)
		size++;
	return (size);
}

int	get_size(char const *s, char c)
{
	int		offset;
	int		size;
	int		i;

	if (!s)
		return (0);
	size = 0;
	i = -1;
	while (s[++i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			size += 1;
			offset = get_offset(s, i, c);
			i += offset;
			break ;
		}
		if (!s[i])
			break ;
	}
	return (size);
}
