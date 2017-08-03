/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 08:43:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/03 10:19:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	model_to_world(t_fdf fdf, float v1[3], float v2[3])
{
	v1[0] = v1[0] * fdf.scale->x + fdf.translation->x + fdf.window->width / 2;
	v1[1] = v1[1] * fdf.scale->y + fdf.translation->y + fdf.window->height / 2;;
	v1[2] = v1[2] * fdf.scale->z + fdf.translation->z;
	v2[0] = v2[0] * fdf.scale->x + fdf.translation->x + fdf.window->width / 2;
	v2[1] = v2[1] * fdf.scale->y + fdf.translation->y + fdf.window->height / 2;;
	v2[2] = v2[2] * fdf.scale->z + fdf.translation->z;
}

static void	world_to_view(t_fdf fdf, float v1[3], float v2[3])
{
	/* check to see if value should be clipped. */
	if (fdf.near == 0)
		return ;
	if (v1[2] == 0)
		v1[2] = 0.001;
	if (v2[2] == 0)
		v2[2] = 0.001;
	v1[0] -= v1[2];
	v1[1] -= v1[2];

	v2[0] -= v2[2];
	v2[1] -= v2[2];
}

static void	fill_vec(float v[3], float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void		plot_grid(t_fdf *fdf)
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
			if (i + 1 < fdf->bp_rows && j + 2 < fdf->bp_cols)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j + 1, i + 1, fdf->blueprint[i + 1][j + 1]);
				world_to_view(*fdf, v1, v2);
				model_to_world(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
			}
			if (i + 1 < fdf->bp_rows)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j, i + 1, fdf->blueprint[i + 1][j]);
				world_to_view(*fdf, v1, v2);
				model_to_world(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
			}
			if (j + 2 < fdf->bp_cols)
			{
				fill_vec(v1, j, i, fdf->blueprint[i][j]);
				fill_vec(v2, j + 1, i, fdf->blueprint[i][j + 1]);
				world_to_view(*fdf, v1, v2);
				model_to_world(*fdf, v1, v2);
				draw_line(fdf->window, v1, v2);
			}
		}
	}
}
