#include "../inc/sudo_solver.h"

void	check_line(char *line, int line_nb, int *valid_bool)
{
	if (ft_strlen(line) != 9)
	{
		ft_fprintf(2, "Row %i is not well sized (9 digits per row)\n", line_nb);
		*valid_bool = 0;
	}
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			ft_fprintf(2, "The char %c on line %i is not a digit\n", *line, line_nb + 1);
			*valid_bool = 0;
		}
		line++;
	}	
}

char	**check_size_n_get_grid(char *content)
{
	char	**grid;
	int		i;
	int		valid_bool;

	grid = ft_split(content, '\n');
	free(content);
	valid_bool = 1;
	i = -1;
	while (grid[++i])
		check_line(grid[i], i, &valid_bool);
	if (i != 9)
	{
		ft_fprintf(2, "The number of row (%i) is not 9\n", i);
		valid_bool = 0;	
	}
	if (valid_bool)
		return (grid);
	else
	{
		free_grid(grid, i);
		return (NULL);
	}
}

char	**err_on_fd(void)
{
	ft_fprintf(2, "Error on opening file : path might not be correct\n");
	return (NULL);
}

char	**parser(char *path)
{
    int		fd;
	char	*tmp;
	char	*content;

    fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err_on_fd());
	content = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		content = strj(content, tmp);
		if (!content)
		{
			close(fd);
			return (NULL);
		}
	}
    close(fd);
	return (check_size_n_get_grid(content));
}