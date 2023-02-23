#include "../inc/sudo_solver.h"

int	arg_error(int argc)
{
	if (argc != 2)
	{
		ft_fprintf(2, "One arg : a file with the sudo grid\n");
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
	print_grid(grid);
	/* solver in here */
	if (!solver(0, 0, '0', grid))
	{
		ft_fprintf(1, "\033[1;32mSudoku is solved.\nGet the solution grid down here:\n\033[0m");
		print_grid(grid);
	}
	free_grid(grid, 9);
	return (0);
}
