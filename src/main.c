/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:56:09 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/24 13:56:12 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sudo_solver.h"

int	arg_error(int argc)
{
	if (argc != 2)
	{
		ft_fprintf(2, "%sOnly one arg : a file with the grid%s\n", RED, END);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**grid;

	if (arg_error(argc))
		return (1);
	grid = parser(argv[1]);
	if (!grid)
		return (2);
	print_grid2(grid);
	if (!solver(0, 0, '0', grid))
		ft_fprintf(1, "%sSudoku is solved. Grid here:%s\n", GREEN_BOLD, END);
	else
		ft_fprintf(1, "%sThis sudoku can not be solved:%s\n", RED_BOLD, END);
	print_grid2(grid);
	free_grid(grid, 9);
	return (0);
}
