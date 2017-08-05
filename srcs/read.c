/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:57:27 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 15:09:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		fdf_get_dims(int fd, short *rows, short *cols)
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

static short	*allocate_ushort_arr(int len)
{
	short	*ret;

	if (!(ret = (short *)malloc(len * sizeof(short))))
		ft_fatal("err: out of memory\n");
	ft_bzero(ret, len * sizeof(short));
	return (ret);
}

static short	*fdf_str_to_ushort_array(char *line, int len, short z_minmax[2])
{
	short	*ret;
	char	*ptr;
	int		i;

	ret = allocate_ushort_arr(len);
	i = 0;
	ptr = line;
	while (*ptr)
	{
		while (*ptr && *ptr != '-' && (*ptr < '0' || *ptr > '9'))
			++ptr;
		if (!*ptr)
			break ;
		ret[i] = ft_atoi(ptr);
		if (ret[i] > z_minmax[1])
			z_minmax[1] = ret[i];
		if (ret[i] < z_minmax[0])
			z_minmax[0] = ret[i];
		while (*ptr && (*ptr == '-' || (*ptr >= '0' && *ptr <= '9')))
			++ptr;
		++i;
	}
	return (ret);
}

short			**read_blueprint(
		char *filepath, short *rows, short *cols, short z_minmax[2])
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
	z_minmax[0] = 0;
	z_minmax[1] = 0;
	i = -1;
	while (get_next_line(fd, &line) > 0)
		blueprint[++i] = fdf_str_to_ushort_array(line, *cols, z_minmax);
	return (blueprint);
}
