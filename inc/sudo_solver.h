/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudo_solver.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:39:12 by bguillau          #+#    #+#             */
/*   Updated: 2023/02/24 14:39:29 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDO_SOLVER_H
# define SUDO_SOLVER_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define RED "\033[31m"
# define RED_BOLD "\033[1;31m"
# define GREEN_BOLD "\033[1;32m"
# define END "\033[0m"

char	**parser(char *path);

void	free_grid(char **grid, int grid_len);
void	print_grid(char **grid);
void	print_grid2(char **grid);

int		verifier(int y, int x, char **grid);

int		solver(int x, int y, char last_try, char **grid);

#endif
