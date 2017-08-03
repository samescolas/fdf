/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/03 15:11:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

int		ft_gradient(t_color c1, t_color c2, int step)
{
	t_color	*ret;

	ret = int_to_col(col_to_int(c1));
	if (c1.r - c2.r != 0)
	{
		if (c1.r > c2.r)
			ret->r = (ret->r + step) % 255;
		else
			ret->r = (ret->r - step) % 255;
	}
	else if (c1.g - c2.g != 0)
	{
		if (c1.g > c2.g)
			ret->g = (ret->g + step) % 255;
		else
			ret->g = (ret->g - step) % 255;
	}
	else if (c1.b - c2.b != 0)
	{
		if (c1.b > c2.b)
			ret->b = (ret->b + step) % 255;
		else
			ret->b = (ret->b - step) % 255;
	}
	return (col_to_int(*ret));
}

void	draw_vertical_line(t_window *win, float v1[3], float v2[3])
{
	int		y1;
	int		y2;

	y1 = MIN(v1[1], v2[1]) - 1;
	y2 = MAX(v1[1], v2[1]);
	while (++y1 < y2)
		mlx_pixel_put(win->mlx, win->win, v1[0], y1, 0xff0000);
}

void	swap_vertices(float *v1, float *v2)
{
	float	*tmp;

	tmp = v1;
	v1 = v2;
	v2 = tmp;
}

void	draw_line(t_fdf fdf, float v1[3], float v2[3])
{
	int		x;
	int		y;
	int		z;
	int		dir;
	int		inc;
	float	delta[3];
	float	err;
	float	derr;
	float	tmp;
	t_window 	*window;

	window = fdf.window;
	if (v1[0] == v2[0])
	{
		draw_vertical_line(window, v1, v2);
		return ; 
	}
	if ((dir = (ABS(v1[0] - v2[0]) > ABS(v1[1] - v2[1]))))
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
	delta[0] = ABS(v2[0] - v1[0]);
	delta[1] = ABS(v2[1] - v1[1]);
	derr = delta[1] / delta[0];
	err = derr - 0.5;

	x = v1[0] - 1;
	y = v1[1];
	z = v1[2];
	inc = (z > v2[2]);
	while (++x < v2[0])
	{
		if (dir)
			mlx_pixel_put(window->mlx, window->win, y, x, 0xff0000);
		else
			mlx_pixel_put(window->mlx, window->win, x, y, 0xff0000);
		err = err + derr;
		if (err > 0.5)
		{
			if (inc)
				z += 1;
			else
				z -= 1;
			y += 1;
			err -= 1;
		}
	}
}
