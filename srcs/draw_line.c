/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/29 14:33:42 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

void	draw_vertical_line(void *mlx, void *win, int x, int y0, int y1)
{
	int		y;

	y = y0 - 1;
	while (++y <= y1)
		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

/*
void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1)
{
	long long	color;
	float		derr;
	float		err;
	int			y;
	int			x;
	int			pixel_count;

	if (x0 == x1)
	{
		draw_vertical_line(mlx, win, x0, y0, y1);
		return ;
	}
	derr = (MAX(y0, y1) - MIN(y0, y1)) / (MAX(x0, x1) - MIN(x0, x1));
	err = derr - 0.5;

	y = MIN(y0, y1);
	x = MIN(x0, x1) - 1;

	color = 0x00FFFFFF;
	pixel_count = 0;
	while (++x < MAX(x0, x1))
	{
		if (pixel_count > 17)
			color -= 242;
		mlx_pixel_put(mlx, win, x, y, color);
		pixel_count += 1;
		err = err + derr;
		if (err >= 0.5)
		{
			y += 1;
			err -= 1;
		}
	}
}
*/

int		ft_gradient(t_color c1, t_color c2)
{
	t_color	*ret;

	ret = int_to_col(col_to_int(c1));
	if (c1.r - c2.r != 0)
	{
		if (c1.r > c2.r)
			ret->r = (ret->r + 11) % 256;
		else
			ret->r = (ret->r - 11) % 256;
	}
	if (c1.g - c2.g != 0)
	{
		if (c1.g > c2.g)
			ret->g = (ret->g + 11) % 256;
		else
			ret->g = (ret->g - 11) % 256;
	}
	if (c1.b - c2.b != 0)
	{
		if (c1.b > c2.b)
			ret->b = (ret->b + 11) % 256;
		else
			ret->b = (ret->b - 11) % 256;
	}
	return (col_to_int(*ret));
}

void	draw_line(t_window *window, t_point a, t_point b)
{
	int		x;
	int		y;
	float	err;
	float	derr;
	int		color;
	int		pixel_count;

	if (a.pos->x == b.pos->x)
	{
		draw_vertical_line(window->mlx, window->win, a.pos->x, a.pos->y, b.pos->y);
		return ;
	}
	derr = (MAX(a.pos->y, b.pos->y) - MIN(a.pos->y, b.pos->y))/
			(MAX(a.pos->x, b.pos->x) - MIN(a.pos->x, b.pos->x));
	err = derr - 0.5;
	y = MIN(a.pos->y, b.pos->y);
	x = MIN(a.pos->x, b.pos->x) - 1;
	color = col_to_int(*(a.col));
	pixel_count = 0;
	while (++x < MAX(a.pos->x, b.pos->x))
	{
		color  = ft_gradient(*(a.col), *(b.col));
		a.col = int_to_col(ft_gradient((*a.col), *(b.col)));
		mlx_pixel_put(window->mlx, window->win, x, y, color);
		pixel_count += 1;
		err = err + derr;
		if (err > 0.5)
		{
			y += 1;
			err -= 1;
		}
	}
}
