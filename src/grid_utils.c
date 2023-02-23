#include "../inc/sudo_solver.h"

void	print_grid(char **grid)
{
	while (*grid)
	{
		ft_fprintf(1, "%s\n", *grid++);
	}
}

void	free_grid(char **grid, int grid_len)
{
	while (grid_len)
		free(grid[--grid_len]);
	free(grid);
}
