#include "../inc/sudo_solver.h"

int	check_row(int y, char **grid)
{
	int	x;
	int	x_tmp;

	x = 0;
	while (x < 9)
	{
		x_tmp = x + 1;
		while (x_tmp < 9)
		{
			if (grid[y][x] != '0' && grid[y][x] == grid[y][x_tmp])
				return (1);
			x_tmp++;
		}
		x++;
	}
	return (0);
}

int	check_col(int x, char **grid)
{
	int	y;
	int	y_tmp;

	y = 0;
	while (y < 9)
	{
		y_tmp = y + 1;
		while (y_tmp < 9)
		{
			if (grid[y][x] != '0' && grid[y][x] == grid[y_tmp][x])
				return (1);
			y_tmp++;
		}
		y++;
	}
	return (0);
}

/* select the sqr of grid[y][x] and turn it into a string */
char	*get_sqr(int y, int x, char **grid)
{
	int		start[2];
	char	*sqr;
	int		i;

	sqr = malloc(10 * sizeof(char));
	if (!sqr)
		return (NULL);
	sqr[9] = '\0';
	start[0] = y / 3 * 3;
	start[1] = x / 3 * 3;
	i = -1;
	while (++i < 3)
		sqr[i] = grid[start[0]][start[1] + i];
	i = -1;
	while (++i < 3)
		sqr[3 + i] = grid[start[0] + 1][start[1] + i];
	i = -1;
	while (++i < 3)
		sqr[6 + i] = grid[start[0] + 2][start[1] + i];
	return (sqr);
}

int	check_sqr(int y, int x, char **grid)
{
	char	*sqr;
	char	*tmp;
	char	*sqr_og;

	sqr = get_sqr(y, x, grid);
	sqr_og = sqr;
	while (*sqr && *(sqr + 1))
	{
		tmp = sqr + 1;
		while (*tmp)
		{
			if (*sqr != '0' && *sqr == *tmp)
			{
				free(sqr_og);
				return (1);
			}
			tmp++;
		}
		sqr++;
	}
	free(sqr_og);
	return (0);
}

int	verifier(int y, int x, char **grid)
{
	if (check_row(y, grid) || check_col(x, grid) || check_sqr(y, x, grid))
	{
		ft_fprintf(1, "\033[31mVerifier (x:%i, y:%i, try:%c) is not ok\n\033[0m", x, y, grid[y][x]);
		return (1);
	}
	ft_fprintf(1, "\033[32mVerifier (x:%i, y:%i, try:%c) is OK\n\033[0m", x, y, grid[y][x]);
	return (0);
}
