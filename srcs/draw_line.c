/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/31 19:33:51 by sescolas         ###   ########.fr       */
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

void	draw_line(t_window *window, t_point a, t_point b)
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
