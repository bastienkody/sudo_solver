/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:11:37 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/24 14:11:39 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (verifier(y, x, grid) || grid[y][x] == '0')
				return (0);
		}
	}
	return (1);
}

void	next_digit(int x, int y, char **grid)
{
	if (x < 8)
		x++;
	else if (y < 8)
	{
		x = 0;
		y++;
	}
	solver(x, y, '0', grid);
}

int	solver(int x, int y, char last_try, char **grid)
{
	if (grid_is_fulfilled(grid))
		return (0);
	if (grid[y][x] == '0')
	{
		while (last_try < '9')
		{
			grid[y][x] = ++last_try;
			if (!verifier(y, x, grid))
				next_digit(x, y, grid);
			if (grid_is_fulfilled(grid))
				return (0);
		}
		grid[y][x] = '0';
		return (1);
	}
	else
		next_digit(x, y, grid);
	if (grid_is_fulfilled(grid))
		return (0);
	return (1);
}
