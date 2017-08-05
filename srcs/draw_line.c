/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 19:11:18 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

static int		dist(int x1, int x2, int y1, int y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

static int		choose_color(t_fdf fdf, float v1[3], float v2[3], int d)
{
	int			length;
	int			step_size[3];
	t_color		*ret;

	if (v1[2] - v2[2] == 0 && v1[2] == 0)
		return (col_to_int(fdf.colors[0]));
	else if (v1[2] - v2[2] == 0)
		return (col_to_int(fdf.colors[1]));
	else
		ret = int_to_col(col_to_int(fdf.colors[0]));
	length = dist(v1[0], v2[0], v1[1], v2[1]);
	step_size[0] = (int)(fdf.colors[0].r - fdf.colors[1].r) /
		(length == 0 ? 1 : length);
	step_size[1] = (int)(fdf.colors[0].g - fdf.colors[1].g) /
		(length == 0 ? 1 : length);
	step_size[2] = (int)(fdf.colors[0].b - fdf.colors[1].b) /
		(length == 0 ? 1 : length);
	ret = int_to_col(col_to_int(fdf.colors[0]));
	ret->r += (step_size[0] * -d);
	ret->g += (step_size[1] * -d);
	ret->b += (step_size[2] * -d);
	free(ret);
	return (col_to_int(*ret));
}

static void		draw(t_fdf fdf, float v1[3], float v2[3], int info[2])
{
	int		x;
	int		y;
	float	slope;
	float	err;

	x = (int)v1[0];
	y = (int)v1[1];
	slope = ABS((v2[1] - v1[1]) / (v2[0] - v1[0]));
	err = slope - 0.5;
	x = v1[0] - 1;
	while (++x < v2[0])
	{
		if (info[0])
			mlx_pixel_put(fdf.window->mlx, fdf.window->win, y, x,
				choose_color(fdf, v1, v2, dist(v1[0], x, v1[1], y)));
		else
			mlx_pixel_put(fdf.window->mlx, fdf.window->win, x, y,
					choose_color(fdf, v1, v2, dist(v1[0], x, v1[1], y)));
		err += slope;
		if (err > 0.5)
		{
			y += info[1];
			err -= 1;
		}
	}
}

static void		swap_vertices(float *v1, float *v2)
{
	float	*tmp;

	tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void			draw_line(t_fdf fdf, float v1[3], float v2[3])
{
	int		info[2];
	float	tmp;

	info[0] = (fabs(v1[1] - v2[1]) > fabs(v1[0] - v2[0]));
	if (info[0])
	{
		tmp = v1[0];
		v1[0] = v1[1];
		v1[1] = tmp;
		tmp = v2[0];
		v2[0] = v2[1];
		v2[1] = tmp;
	}
	if (v1[0] > v2[0])
		swap_vertices(v1, v2);
	info[1] = (v1[1] > v2[1] ? -1 : 1);
	draw(fdf, v1, v2, info);
}
