#ifndef SUDO_SOLVER_H
# define SUDO_SOLVER_H

#include <stdlib.h>
#include <fcntl.h>
#include "../libft/libft.h"

char	**parser(char *path);

void	free_grid(char **grid, int grid_len);
void	print_grid(char **grid);

int		verifier(int y, int x, char **grid);

int		solver(int x, int y, char last_try, char **grid);

#endif
