/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:57:27 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/31 14:16:42 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

void	fdf_get_dims(int fd, short *rows, short *cols)
{
	char	*line;
	int		i;

	*rows = 1;
	*cols = 1;
	if (get_next_line(fd, &line) <= 0)
		ft_fatal("err: invalid file type\n");
	i = -1;
	while (line[++i])
	{
		while (line[i] && line[i] >= '0' && line[i] <= '9')
			++i;
		*cols += 1;
		while (line[i] && line[i] == ' ')
			++i;
	}
	while (get_next_line(fd, &line))
		*rows += 1;
	ft_strdel(&line);
}

short	*allocate_ushort_arr(int len)
{
	short	*ret;

	if (!(ret = (short *)malloc(len * sizeof(short))))
		ft_fatal("err: out of memory\n");
	ft_bzero(ret, len * sizeof(short));
	return (ret);
}

short	*fdf_str_to_ushort_array(char *line, int len)
{
	short	*ret;
	char	*ptr;
	int		i;

	ret = allocate_ushort_arr(len);
	i = 0;
	ptr = line;
	while (*ptr)
	{
		while (*ptr && (*ptr < '0' || *ptr > '9'))
			++ptr;
		if (!*ptr)
			break ;
		if (ft_strncmp(ptr, "0x", 2) == 0)
			ret[i++] = ft_atoi_hex(ptr + 2);
		else
			ret[i++] = ft_atoi(ptr);
		while (*ptr && (*ptr >= '0' && *ptr <= '9'))
			++ptr;
	}
	return (ret);
}

short	**read_blueprint(char *filepath, short *rows, short *cols)
{
	short	**blueprint;
	char	*line;
	int		fd;
	int		i;

	if ((fd = open(filepath, O_RDONLY)) > 0)
	{
		fdf_get_dims(fd, rows, cols);
		close(fd);
		if ((fd = open(filepath, O_RDONLY)) < 0)
			ft_fatal("err: something went wrong\n");
	}
	else
		ft_fatal("err: unable to open file\n");
	if (!(blueprint = (short **)malloc(*cols * sizeof(short *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		blueprint[++i] = fdf_str_to_ushort_array(line, *cols);
	}
	return (blueprint);
}