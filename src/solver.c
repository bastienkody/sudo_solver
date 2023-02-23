#include "../inc/sudo_solver.h"

int	grid_is_fulfilled(char **grid)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			if (!ft_isdigit(grid[y][x]) || grid[y][x] == '0')
				return (0);
		}
	}
	return (1);
}

/* does not work. able to back track but does not work (pb rewrite on old pos i guess)*/
int	solver(int x, int y, char last_try, char **grid)
{
	ft_fprintf(1, "---------------------------------\n");
	ft_fprintf(1, "solver begins (x:%i, y:%i)\n", x, y);
	print_grid(grid);
	ft_fprintf(1, "---------------------------------\n");
	if (grid_is_fulfilled(grid)) // solved ! 
		exit(EXIT_SUCCESS);
	if (grid[y][x] == '0') // current digit is 0 --> find solution
	{
		while (last_try < '9')
		{
			grid[y][x] = ++last_try;
			if (!verifier(y, x, grid)) // si last try is ok, go recursivly to the next 
			{
				ft_fprintf(1, "solver(next digit)\n");
				solver(x, y, '0', grid);
			}
			//else
		}
		grid[y][x] = '0';
		return (1);
	}
	else 
	{
		if (x < 8)
			x++;
		else if (y < 8)
		{
			x = 0;
			y++;
		}
		ft_fprintf(1, "return solver next digit (current one was not 0)\n");
		return (solver(x, y, '0', grid));
	}
}
