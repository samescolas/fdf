/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/30 12:27:30 by sescolas         ###   ########.fr       */
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
	int				scale;
	t_point			*a;
	t_point			*b;

	scale = 10;
	i = -1;
	while (++i < fdf->bp_rows)
	{
		j = -1;
		while (++j < fdf->bp_cols - 1)
		{
			if (i + 1 < fdf->bp_rows)
			{
				a = create_point(
						create_coord(j, i, fdf->blueprint[i][j]),
						create_color(255, 0, 0),
				  		scale);
				b = create_point(
						create_coord(j, i + 1, fdf->blueprint[i][j]),
						create_color(0, 0, 0),
						scale);
				draw_line(fdf->window, *a, *b);
			}
			if (j + 2 < fdf->bp_cols)
			{
				a = create_point(
						create_coord(j, i, fdf->blueprint[i][j]),
						create_color(255, 0, 0),
						scale);
				b = create_point(
						create_coord(j + 1, i, fdf->blueprint[i][j]),
						create_color(0, 0, 0),
						scale);
				draw_line(fdf->window, *a, *b);
			}
		}
	}
}

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
