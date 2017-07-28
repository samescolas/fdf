#include <unistd.h>
#include <fcntl.h>
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

void	resize_blueprint(unsigned short ***blueprint, unsigned short rows);

unsigned short		**read_bp(
		char *filepath,
		unsigned short *rows,
		unsigned short *cols)
{
	unsigned short	**blueprint;
	char			*line;
	char			*ptr;
	int				fd;

	if ((fd = open(filepath, O_RDONLY)) < 0)
		ft_fatal("fdf: unable to open file\n");
	*rows = -1;
	while (get_next_line(fd, &line) > 0)
	{
		if (*rows > 0 && *rows % 100 == 0)
			resize_blueprint(&blueprint, *rows);
		*cols = 0;
		blueprint[*rows][(*cols)++] = (unsigned short)ft_atoi(line);
		while ((ptr = ft_strchr(ptr, ' ')))
			blueprint[*rows][(*cols)++] = (unsigned short)ft_atoi(ptr);
	}
	return (blueprint);
}

void	resize_blueprint(unsigned short ***blueprint, unsigned short rows)
{
	unsigned short	**ret;
	int				i;
	
	if (!(ret =
			(unsigned short **)malloc((rows + 100) * sizeof(unsigned short))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < rows)
		ret[i] = (*blueprint)[i];
	free(*blueprint);
	*blueprint = ret;
}

/*
char	***get_bp(char *filepath, unsigned short *rows, unsigned short *cols)
{
	char			**grid;
	char			*line;
	int				fd;
	unsigned short	len;

	if (!(grid = (char **)malloc(100 * sizeof(char *))))
		ft_fatal("err: out of memory\n");
	if ((fd = open(filepath, O_RDONLY)) < 0)
		ft_fatal("err: out of memory\n");
	len = 0;
	*rows = -1;
	while (++(rows) < 100 && get_next_line(fd, &line) > 0)
	{
		if (len == 0)
			len = (unsigned short)ft_strcount(line, ' ') + 1;
		grid[*rows] = fdf_split_to_ushort(line, len);
	}
	*cols = -1;
	return (grid);
}
*/
