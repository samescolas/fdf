/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/03 18:03:30 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

void	print_grid(short **grid, short rows, short cols)
{
	int				i;
	int				j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		ft_putstr("[");
		while (++j < cols)
		{
			if (grid[i][j] <= 9 && j > 0)
				write(1, " ", 1);
			if (j > 0)
				write(1, " ", 1);
			ft_putnbr(grid[i][j]);
		}
		ft_putendl("]");
	}
}

int		main(int argc, char **argv)
{
	t_fdf			*fdf;

	if (argc == 2)
	{
		if (!(fdf = fdf_init(1200, 800, "Testing...", argv[1])))
			return (0);
		mlx_expose_hook(fdf->window->win, &display_loop, fdf);
		mlx_key_hook(fdf->window->win, &keypress, fdf);
		mlx_loop(fdf->window->mlx);
	}
	ft_atexit();
	return (0);
}
