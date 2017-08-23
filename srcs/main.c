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
	char			*fp;

	if (argc == 2)
	{
		fp = argv[1];
		if (!(fdf = fdf_init(1200, 800, "Testing...", fp)))
			return (0);
		assign_hooks(fdf);
	}
	else
		ft_fatal("usage: ./fdf [-c 0xc1,0xc2] file\n");
	return (0);
}
