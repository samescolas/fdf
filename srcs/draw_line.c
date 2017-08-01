/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/01 10:51:14 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

int		ft_gradient(t_color c1, t_color c2)
{
	t_color	*ret;

	ret = int_to_col(col_to_int(c1));
	if (c1.r - c2.r != 0)
	{
		if (c1.r > c2.r)
			ret->r = (ret->r + 11) % 255;
		else
			ret->r = (ret->r - 11) % 255;
	}
	else if (c1.g - c2.g != 0)
	{
		if (c1.g > c2.g)
			ret->g = (ret->g + 11) % 255;
		else
			ret->g = (ret->g - 11) % 255;
	}
	else if (c1.b - c2.b != 0)
	{
		if (c1.b > c2.b)
			ret->b = (ret->b + 11) % 255;
		else
			ret->b = (ret->b - 11) % 255;
	}
	return (col_to_int(*ret));
}

void	draw_vertical_line(t_window *win, t_point a, t_point b)
{
	int		y;

	y = MIN(a.pos->y, b.pos->y) - 1;
	while (++y <= MAX(a.pos->y, b.pos->y))
	{
		a.col = int_to_col(ft_gradient(*(a.col), *(b.col)));
		mlx_pixel_put(win->mlx, win->win, a.pos->x, y, col_to_int(*(a.col)));
	}
}

void	draw_line(t_window *window, float v1[3], float v2[3])
{
	int		x;
	int		y;
	int		dir;
	float	delta[3];
	float	err;
	float	derr;
	float	tmp;

	if (v1[0] == v2[0])
		return ;
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
	{
		tmp = v1[0];
		v1[0] = v2[0];
		v2[0] = tmp;
		tmp = v1[1];
		v1[1] = v2[1];
		v2[1] = tmp;
		tmp = v1[2];
		v1[2] = v2[2];
		v2[2] = tmp;
	}
	delta[0] = ABS(v2[0] - v1[0]);
	delta[1] = ABS(v2[1] - v1[1]);
	derr = delta[1] / delta[0];
	err = derr - 0.5;

	x = v1[0] - 1;
	y = v1[1];
	while (++x < v2[0])
	{
		if (dir)
			mlx_pixel_put(window->mlx, window->win, y, x, 0xff);
		else
			mlx_pixel_put(window->mlx, window->win, x, y, 0xff);
		err = err + derr;
		if (err > 0.5)
		{
			y += 1;
			err -= 1;
		}
	}
}
/*
void	draw_line2(t_window *window, t_point a, t_point b)
{
	int		x;
	int		y;
	float	err;
	float	derr;

	if (a.pos->z != 0)
	{
		a.pos->x += 7;
		a.pos->y += 7;
		b.pos->x += 7;
		b.pos->y += 7;
	}
	else if (b.pos->z != 0)
	{
		a.pos->x += 7;
		a.pos->y += 7;
		b.pos->x += 7;
		b.pos->y += 7;
	}
	if (a.pos->x == b.pos->x)
	{
		draw_vertical_line(window, a, b);
		return ;
	}
	derr = (MAX(a.pos->y, b.pos->y) - MIN(a.pos->y, b.pos->y))/
			(MAX(a.pos->x, b.pos->x) - MIN(a.pos->x, b.pos->x));
	err = derr - 0.5;
	y = MIN(a.pos->y, b.pos->y);
	x = MIN(a.pos->x, b.pos->x);
	while (++x < MAX(a.pos->x, b.pos->x))
	{
		a.col = int_to_col(ft_gradient((*a.col), *(b.col)));
		mlx_pixel_put(window->mlx, window->win, x, y, col_to_int(*(a.col)));
		err = err + derr;
		if (err > 0.5)
		{
			y += 1;
			err -= 1;
		}
	}
}
*/
