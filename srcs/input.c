#include <unistd.h>
#include <fcntl.h>
#include "../libs/libft/libft.h"

char	***get_grid(char *filepath)
{
	char	***grid;
	char	*line;
	int		rows;
	int		fd;

	if (!(grid = (char ***)malloc(100 * sizeof(char **))))
		return ((void *)0);
	if ((fd = open(filepath, O_RDONLY)) < 0)
		return ((void *)0);
	rows = -1;
	while (++rows < 100 && get_next_line(fd, &line) > 0)
		grid[rows] = ft_strsplit(line, ' ');
	return (grid);
}
