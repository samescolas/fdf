#include <unistd.h>
#include <fcntl.h>
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

void			resize_blueprint(unsigned short ***blueprint, unsigned short rows);
unsigned short	*create_row(int len);

void			print_row(unsigned short *row)
{
	int		len;
	int		i;

	len = sizeof(row) / sizeof(row[0]);
	i = -1;
	while (++i < len)
		ft_putnbr(row[i]);
}

int				fdf_get_len(char *line)
{
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (line[++i])
	{
		while (line[i] && line[i] >= '0' && line[i] <= '9')
			++i;
		++len;
		while (line[i] && line[i] == ' ')
			++i;
	}
	return (len + 1);
}

unsigned short	**read_bp(
		char *filepath,
		unsigned short *rows,
		unsigned short *cols)
{
	unsigned short	**blueprint;
	char			*line;
	char			*ptr;
	int				fd;
	int				len;

	if (!(blueprint = (unsigned short **)malloc(100 * sizeof(unsigned short))))
		ft_fatal("err: out of memory\n");
	if ((fd = open(filepath, O_RDONLY)) < 0)
		ft_fatal("fdf: unable to open file\n");
	*rows = 0;
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (len == 0)
			len = fdf_get_len(line);
		if (*rows > 0 && *rows % 100 == 0)
			resize_blueprint(&blueprint, *rows);
		blueprint[*rows] = create_row(len);
		*cols = 0;
		ptr = line;
		while (*ptr)
		{
			while(*ptr && (*ptr < '0' || *ptr > '9'))
				++ptr;
			blueprint[*rows][(*cols)++] = ft_atoi(ptr);
			ft_putnbr(ft_atoi(ptr) /10);
			write(1, " ", 1);
			while (*ptr && (*ptr >= '0' && *ptr <= '9'))
				++ptr;
		}
		*rows += 1;
	}
	return (blueprint);
}

unsigned short	*create_row(int len)
{
	unsigned short	*ret;

	if (!(ret = (unsigned short *)malloc(len * sizeof(unsigned short))))
		ft_fatal("err: out of memory\n");
	ft_bzero(ret, len * sizeof(unsigned short));
	return (ret);
}

void			resize_blueprint(unsigned short ***blueprint, unsigned short rows)
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
