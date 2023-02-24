/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:55:51 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/24 13:55:55 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sudo_solver.h"

void	print_grid(char **grid)
{
	while (*grid)
	{
		ft_fprintf(1, "%s\n", *grid++);
	}
}

void	print_grid2(char **grid)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			if (!(x % 3))
				ft_putchar_fd('|', 1);
			ft_putchar_fd(grid[y][x], 1);
		}
		ft_putchar_fd('|', 1);
		ft_putchar_fd('\n', 1);
		if (y == 2 || y == 5)
			ft_fprintf(1, "-------------\n");
	}
}

void	free_grid(char **grid, int grid_len)
{
	while (grid_len)
		free(grid[--grid_len]);
	free(grid);
}
