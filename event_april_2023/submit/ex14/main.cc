#include "iostream"
#include "unistd.h"
#include "cstdio"
// #include "cstdlib"
#include "string" // stoi

using	namespace std;

void	put_level(int wbottom, int wlevel, int wdoor);
int	cal_tiles(int row, int hope, int i);
void	pyramid(int size);


// DRIVE

int	main(int c, char **v)
{
	int	level;

	if (c ^ 2)
		return 0;
	level = stoi(v[1]);
	if (level < 1)
		return 0;
	pyramid(level);
}


// helpers

void	pyramid(int size)
{
	int	i;
	int	max_row;
	int	wbottom;

	i = 1;
	max_row = cal_tiles(0, 1, size);
	wbottom = cal_tiles(max_row, 4, 0);
	if (size > 0)
	{
		size = (size % 2 == 0 ? size - 1 : size);
		while (max_row--)
			put_level(wbottom, cal_tiles(i++, 4, 0), size);
	}
}

//
// put_level takes in 3 widths
//	:: width of the bottom of (wbottom)
//	:: width of current row (level)
//	:: width wdoor (wdoor)
//


void	put_level(int wbottom, int wlevel, int wdoor)
{
	int	i = -1;

	while (++i < wbottom)
	{
		if (i < (wbottom / 2) - (wlevel / 2) || i > (wbottom / 2) + (wlevel / 2))
		{
			write(1, " ", 1);
			continue ;
		}if (i == (wbottom / 2) - (wlevel / 2) || i == (wbottom / 2) + (wlevel / 2))
		{
			i == (wbottom / 2) - (wlevel / 2) ? write(1, "/", 1) : write(1, "\\", 1);
			continue ;
		}
		if ( wbottom - wlevel <= wdoor * 2 - 1 &&
			(i >= (wbottom / 2) - (wdoor / 2) && i <= (wbottom / 2) + (wdoor / 2))
		)
		{
			(wdoor > 3) && (i == (wbottom / 2) + (wdoor / 2) - 1)
			&& (wbottom - wlevel == wdoor - 1)
			? write (1, "$", 1) : write (1, "|", 1);
			continue ;
		}
		write(1, "*", 1);
	}
	write(1, "\n", 1);
}

/* 
1 : max total of level a pyramid of i
2 : Tier that current row is in
3 : char progression for tier changes
4 : width of row i
*/

int	cal_tiles(int row, int hope, int i)
{
	if (hope == 1)
		return(i == 1 ? 3 : (i + 2) + cal_tiles(0, 1, i - 1));
	if (hope == 2)
	{
		if (row > 3)
			return (row > cal_tiles(0, 1, i) ? cal_tiles(row, 2, i + 1) : i);
		return (1);
	}
	if (hope == 3)
		return (i % 2 == 0 ? i + 4 : i + 3);
	if (row > 1)
		return (cal_tiles(row, 2, 1) == cal_tiles(row - 1, 2, 1)
			? 2 + cal_tiles(row -1, 4, cal_tiles(0, 3, cal_tiles(row - 1, 2, 1)))
			: cal_tiles(0, 3, cal_tiles(row, 2, 1))
				+ cal_tiles(row - 1, 4, cal_tiles(0, 3, cal_tiles(row - 1, 2, 1))));
	return (3);
}

