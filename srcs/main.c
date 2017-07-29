/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/29 10:58:24 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

void	print_grid2(t_fdf *fdf)
{
	int				i;
	int				j;

	i = -1;
	while (++i < fdf->bp_rows)
	{
		j = -1;
		while (++j < fdf->bp_cols)
		{
			if (fdf->blueprint[i][j])
				draw_line(fdf->window->mlx, fdf->window->window, j*10, (j*10) + 10, (i*10), (i*10) + 10);
		}
	}
}

void	print_grid(unsigned short **grid, unsigned short rows, unsigned short cols)
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
		if (!(fdf = fdf_init(400, 400, "Testing...", argv[1])))
			return (0);
		print_grid2(fdf);

		mlx_loop(fdf->window->mlx);
	}
	else
	{
		ft_putnbr(ft_atoi_hex("11"));
	}
	ft_atexit();
	return (0);
}
