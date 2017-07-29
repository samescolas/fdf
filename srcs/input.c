#include <unistd.h>
#include <fcntl.h>
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

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

unsigned short	*allocate_ushort_arr(int len)
{
	unsigned short	*ret;

	if (!(ret = (unsigned short *)malloc(len * sizeof(unsigned short))))
		ft_fatal("err: out of memory\n");
	ft_bzero(ret, len * sizeof(unsigned short));
	return (ret);
}

unsigned short	*fdf_str_to_ushort_array(char *line, int len)
{
	unsigned short	*ret;
	char			*ptr;
	int				i;

	ret = allocate_ushort_arr(len);
	i = 0;
	ptr = line;
	while (*ptr)
	{
		while (*ptr && (*ptr < '0' || *ptr > '9'))
			++ptr;
		ret[i++] = ft_atoi(ptr);
		while (*ptr && (*ptr >= '0' && *ptr <= '9'))
			++ptr;
	}
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

unsigned short	**read_bp(
		char *filepath,
		unsigned short *rows,
		unsigned short *cols)
{
	unsigned short	**blueprint;
	char			*line;
	int				fd;

	if (!(blueprint = (unsigned short **)malloc(100 * sizeof(unsigned short))))
		ft_fatal("err: out of memory\n");
	if ((fd = open(filepath, O_RDONLY)) < 0)
		ft_fatal("fdf: unable to open file\n");
	*rows = 0;
	*cols = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*cols == 0)
			*cols = fdf_get_len(line);
		if (*rows > 0 && *rows % 100 == 0)
			resize_blueprint(&blueprint, *rows);
		blueprint[(*rows)++] = fdf_str_to_ushort_array(line, *cols);
	}
	return (blueprint);
}
