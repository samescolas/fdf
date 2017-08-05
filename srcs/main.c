/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 15:08:48 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	read_colors(int colors[2], char *col_string)
{
	char	*delim;

	if (!(delim = ft_strchr(col_string, ',')))
		return (-1);
	colors[0] = ft_atoi_hex(ft_strchr(col_string, 'x') + 1);
	colors[1] = ft_atoi_hex(ft_strchr(delim + 1, 'x') + 1);
	if (colors[0] == 0 && colors[1] == 0)
		return (-1);
	return (0);
}

static void	assign_hooks(t_fdf *fdf)
{
	mlx_do_key_autorepeatoff(fdf->window->mlx);
	mlx_expose_hook(fdf->window->win, display_loop, fdf);
	mlx_hook(fdf->window->win, 2, 0, keypress, fdf);
	mlx_hook(fdf->window->win, 3, 0, keyrelease, fdf);
	mlx_loop_hook(fdf->window->mlx, display_loop, fdf);
	mlx_loop(fdf->window->mlx);
}

int			main(int argc, char **argv)
{
	t_fdf			*fdf;
	int				colors[2];
	char			*fp;

	if (argc == 4 && ft_strcmp(argv[1], "-c") == 0)
	{
		if (read_colors(colors, argv[2]) < 0)
			ft_fatal("usage: ./fdf [-c 0xbottom_color,0xtop_color] file\n");
		fp = argv[3];
	}
	else
		fp = argv[1];
	if (argc == 2 || argc == 4)
	{
		if (!(fdf = fdf_init(1200, 800, "Testing...", fp)))
			return (0);
		if (argc == 4)
			assign_colors(fdf, colors[0], colors[1]);
		assign_hooks(fdf);
	}
	else
		ft_fatal("usage: ./fdf [-c 0xc1,0xc2] file\n");
	return (0);
}
