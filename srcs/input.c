/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:57:27 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/29 13:25:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

short	*allocate_ushort_arr(int len)
{
	short	*ret;

	if (!(ret = (short *)malloc(len * sizeof(short))))
		ft_fatal("err: out of memory\n");
	ft_putstr("allocating ");
	ft_putnbr(len);
	ft_putendl(" bytes");
	ft_bzero(ret, len * sizeof(short));
	return (ret);
}

short	*fdf_str_to_ushort_array(char *line, int len)
{
	short	*ret;
	char			*ptr;
	int				i;

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

void			resize_blueprint(
		short ***blueprint,
		short rows)
{
	short	**ret;
	int				i;

	ft_putstr("entering resize\n");
	if (!(ret =
			(short **)malloc((rows + 100) * sizeof(short))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < rows)
		ret[i] = (*blueprint)[i];
	free(*blueprint);
	*blueprint = ret;
	ft_putstr("leaving resize\n");
}

short	**read_blueprint(
		char *filepath,
		short *rows,
		short *cols)
{
	short	**blueprint;
	char			*line;
	int				fd;

	if (!(blueprint = (short **)malloc(100 * sizeof(short))))
		ft_fatal("err: out of memory\n");
	if ((fd = open(filepath, O_RDONLY)) < 0)
		ft_fatal("fdf: unable to open file\n");
	*rows = 0;
	*cols = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_putnbr(*rows);
		ft_putstr(" ");
		ft_putendl("looping...");
		if (*cols == 0)
			*cols = fdf_get_len(line);
		if (*rows > 0 && (*rows + 1) % 100 == 0)
			resize_blueprint(&blueprint, *rows);
		blueprint[(*rows)++] = fdf_str_to_ushort_array(line, *cols);
	}
	return (blueprint);
}
