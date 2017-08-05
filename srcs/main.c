/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 19:31:13 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

static int	read_colors(int colors[2], char *col_string)
{
	char	*delim;

	if (!(delim = ft_strchr(col_string, ',')))
		return (-1);
	colors[0] = ft_atoi(col_string);
	colors[1] = ft_atoi(delim + 1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf			*fdf;
	int				colors[2];
	char			*fp;

	colors[0] = 0;
	if (argc == 4 && ft_strcmp(argv[1], "-c") == 0)
	{
		if (read_colors(colors, argv[2]) < 0)
			ft_fatal("usage: ./fdf [-c 0xc1,0xc2] file\n");
		fp = argv[3];
	}
	else
		fp = argv[1];
	if (argc == 2 || (argc == 4 && colors[0] != 0))
	{
		if (!(fdf = fdf_init(1200, 800, "Testing...", fp)))
			return (0);
		if (argc == 4)
			assign_colors(fdf, colors[0], colors[1]);
		mlx_expose_hook(fdf->window->win, &display_loop, fdf);
		mlx_key_hook(fdf->window->win, &keypress, fdf);
		mlx_loop(fdf->window->mlx);
	}
	else
		ft_fatal("usage: ./fdf [-c 0xc1,0xc2] file\n");
	return (0);
}
