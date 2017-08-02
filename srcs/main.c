/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/02 15:13:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

void	model_to_world(t_fdf fdf, float v1[3], float v2[3])
{
	v1[0] = v1[0] * fdf.scale->x + fdf.translation->x;
	v1[1] = v1[1] * fdf.scale->y + fdf.translation->y;
	v1[2] = v1[2] * fdf.scale->z + fdf.translation->z;
	v2[0] = v2[0] * fdf.scale->x + fdf.translation->x;
	v2[1] = v2[1] * fdf.scale->y + fdf.translation->y;
	v2[2] = v2[2] * fdf.scale->z + fdf.translation->z;
}

void	world_to_view(t_fdf fdf, float v1[3], float v2[3])
{
	float	scale;

	scale = tan(fdf.fov / 2 * M_PI / 180) * fdf.near;

	//v1[0] = (2 * v1[0] * fdf.near) / (2 * fdf.far);
	//v1[1] = (2 * v1[1] * fdf.near) / (2 * fdf.far);

	//v2[0] = (2 * v2[0] * fdf.near) / (2 * fdf.far);
	//v2[1] = (2 * v2[1] * fdf.near) / (2 * fdf.far);

	v1[0] = v1[0] / (v1[2] == 0 ? 1 : v1[2]);
	v1[1] = v1[1] / (v1[2] == 0 ? 1 : v1[2]);

	v2[0] = v2[0] / (v2[2] == 0 ? 1 : v2[2]);
	v2[1] = v2[1] / (v2[2] == 0 ? 1 : v2[2]);
}

void	fill_vec(float v[3], float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void	plot_grid(t_fdf *fdf)
{
	int				i;
	int				j;
	float			v1[3];
	float			v2[3];

	i = -1;
	while (++i < fdf->bp_rows)
	{
		j = -1;
		while (++j < fdf->bp_cols - 1)
		{
			if (0 && i + 1 < fdf->bp_rows && j + 2 < fdf->bp_cols)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j + 1, i + 1, fdf->blueprint[i + 1][j + 1]);
				model_to_world(*fdf, v1, v2);
				world_to_view(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
			}
			if (i + 1 < fdf->bp_rows)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j, i + 1, fdf->blueprint[i + 1][j]);
				model_to_world(*fdf, v1, v2);
				world_to_view(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
			}
			if (j + 2 < fdf->bp_cols)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j + 1, i, fdf->blueprint[i][j + 1]);
				model_to_world(*fdf, v1, v2);
				world_to_view(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
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
		if (!(fdf = fdf_init(1200, 800, "Testing...", argv[1])))
			return (0);
		plot_grid(fdf);
		fdf->translation->y += 10;
		plot_grid(fdf);
		mlx_loop(fdf->window->mlx);
	}
	ft_atexit();
	return (0);
}
