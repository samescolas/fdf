/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 08:43:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 18:59:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Shift to origin, scale, rotate, shift to desired position
*/

static void	normalize(t_fdf fdf, float v1[3], float v2[3])
{
	v1[0] -= (fdf.bp_cols / 2);
	v1[1] -= (fdf.bp_rows / 2);
	v2[0] -= (fdf.bp_cols / 2);
	v2[1] -= (fdf.bp_rows / 2);
	v1[0] *= fdf.scale->x;
	v1[1] *= fdf.scale->y;
	v1[2] *= fdf.scale->z;
	v2[0] *= fdf.scale->x;
	v2[1] *= fdf.scale->y;
	v2[2] *= fdf.scale->z;
	apply_rotation(fdf.rotation, v1, v2);
	v1[0] += fdf.translation->x;
	v1[1] += fdf.translation->y;
	v1[2] += fdf.translation->z;
	v2[0] += fdf.translation->x;
	v2[1] += fdf.translation->y;
	v2[2] += fdf.translation->z;
}

static void	fill_vec(float v[3], float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

static void	transform_and_draw(t_fdf *fdf, int x, int y, int vert)
{
	float	v1[3];
	float	v2[3];

	fill_vec(v1, x, y, fdf->blueprint[y][x]);
	if (vert)
		fill_vec(v2, x, y + 1, fdf->blueprint[y + 1][x]);
	else
		fill_vec(v2, x + 1, y, fdf->blueprint[y][x + 1]);
	normalize(*fdf, v1, v2);
	v1[2] = fdf->blueprint[y][x];
	v2[2] = fdf->blueprint[y][x + 1];
	draw_line(*fdf, v1, v2);
}

void		plot_grid(t_fdf *fdf)
{
	int				row;
	int				col;

	row = -1;
	while (++row < fdf->bp_rows)
	{
		col = -1;
		while (++col < fdf->bp_cols)
		{
			if (row + 1 < fdf->bp_rows)
				transform_and_draw(fdf, col, row, 1);
			if (col + 1 < fdf->bp_cols)
				transform_and_draw(fdf, col, row, 0);
		}
	}
}

int			display_loop(t_fdf *fdf)
{
	mlx_clear_window(fdf->window->mlx, fdf->window->win);
	plot_grid(fdf);
	return (0);
}
