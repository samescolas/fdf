/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 12:14:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

#include <stdio.h>

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

void	draw_it(t_fdf fdf, float v1[3], float v2[3], int yx)
{
	int		x;
	int		y;
	float	slope;
	float	err;

	ft_putstr("LINESLINES LINES (");
	ft_putnbr((int)v1[0]);
	ft_putstr(", ");
	ft_putnbr((int)v1[1]);
	ft_putstr(", ");
	ft_putnbr((int)v1[2]);
	ft_putstr(") and (");
	ft_putnbr((int)v2[0]);
	ft_putstr(", ");
	ft_putnbr((int)v2[1]);
	ft_putstr(", ");
	ft_putnbr((int)v2[2]);
	ft_putendl(")");
	x = (int)v1[0];
	y = (int)v1[1];
	slope = ABS((v2[1] - v1[1]) / (v2[0] - v1[0]));
	if (slope == 0)
		ft_putendl("YOU SHOULD SEE THIS A LOT!");
	else
		printf("%f\n", slope);
	err = slope - 0.5;
	x = v1[0] - 1;
	while (++x < v2[0])
	{
		ft_putstr("looping");
		if (yx)
			mlx_pixel_put(fdf.window->mlx, fdf.window->win, y, x, 0xff);
		else
			mlx_pixel_put(fdf.window->mlx, fdf.window->win, x, y, 0xff);
		err += slope;
		if (err > 0.5)
		{
			if (v1[1] > v2[1])
				y -= 1;
			else
				y += 1;
			err -= 1;
		}
	}
}

void	draw_vertical_line(t_window *win, float v1[3], float v2[3])
{
	int		y1;
	int		y2;

	ft_putstr("drawing vertical line between (");
	ft_putnbr((int)v1[0]);
	ft_putstr(", ");
	ft_putnbr((int)v1[1]);
	ft_putstr(", ");
	ft_putnbr((int)v1[2]);
	ft_putstr(") and (");
	ft_putnbr((int)v2[0]);
	ft_putstr(", ");
	ft_putnbr((int)v2[1]);
	ft_putstr(", ");
	ft_putnbr((int)v2[2]);
	ft_putendl(")");
	y1 = MIN(v1[1], v2[1]) - 1;
	y2 = MAX(v1[1], v2[1]);
	while (++y1 < y2)
		mlx_pixel_put(win->mlx, win->win, v1[0], y1, 0xff);
}

void	swap_vertices(float *v1, float *v2)
{
	float	*tmp;

	ft_putstr("\n\n\nswapping (");
	ft_putnbr((int)v1[0]);
	ft_putstr(", ");
	ft_putnbr((int)v1[1]);
	ft_putstr(", ");
	ft_putnbr((int)v1[2]);
	ft_putstr(") and (");
	ft_putnbr((int)v2[0]);
	ft_putstr(", ");
	ft_putnbr((int)v2[1]);
	ft_putstr(", ");
	ft_putnbr((int)v2[2]);
	ft_putendl(")");
	tmp = v1;
	v1 = v2;
	v2 = tmp;
	ft_putstr("swapped (");
	ft_putnbr((int)v1[0]);
	ft_putstr(", ");
	ft_putnbr((int)v1[1]);
	ft_putstr(", ");
	ft_putnbr((int)v1[2]);
	ft_putstr(") and (");
	ft_putnbr((int)v2[0]);
	ft_putstr(", ");
	ft_putnbr((int)v2[1]);
	ft_putstr(", ");
	ft_putnbr((int)v2[2]);
	ft_putendl(")");
}
/*
void	draw_line(t_fdf fdf, float v1[3], float v2[3])
{
	float 	delta[3];
	float	p;
	int		x;
	int		y;
	int		dir;

	delta[0] = ABS(v1[0] - v2[0]);
	delta[1] = ABS(v1[1] - v2[1]);

	p = 2 * delta[1] - delta[0];
	if (v1[0] > v2[0])
		swap_vertices(v1, v2);
	if (v1[1] > v2[1])
		dir = -1;
	else
		dir = 1;
	x = v1[0];
	y = v1[1];
	while (x <= v2[0])
	{
		if (p < 0)
		{
			x = x + 1;
			p = p + 2 * delta[1];
		}
		else
		{
			x = x + 1;
			y = y + dir;
			p = p + 2 * (delta[1] - delta[0]);
		}
		mlx_pixel_put(fdf.window->mlx, fdf.window->win, y, x, 0xff);
	}
}
*/
void	draw_line(t_fdf fdf, float v1[3], float v2[3])
{
	//int		x;
	//int		y;
	int		yx;
	//int		y_dir;
	//float	delta[3];
	//float	err;
	//float	slope;
	float	tmp;
	t_window 	*window;

	ft_putstr("drawing line between (");
	ft_putnbr((int)v1[0]);
	ft_putstr(", ");
	ft_putnbr((int)v1[1]);
	ft_putstr(", ");
	ft_putnbr((int)v1[2]);
	ft_putstr(") and (");
	ft_putnbr((int)v2[0]);
	ft_putstr(", ");
	ft_putnbr((int)v2[1]);
	ft_putstr(", ");
	ft_putnbr((int)v2[2]);
	ft_putendl(")");

	window = fdf.window;
	if (v1[0] == v2[0])
	{
		draw_vertical_line(window, v1, v2);
		return ; 
	}
	if (ABS(v1[1] - v2[1]) > ABS(v1[0] - v2[0]) && v1[1] - v2[1] != 0)
	{
		yx = 1;
		tmp = v1[0];
		v1[0] = v1[1];
		v1[1] = tmp;
		tmp = v2[0];
		v2[0] = v2[1];
		v2[1] = tmp;
	}
	else
		yx = 0;
	if (v1[0] > v2[0])
		swap_vertices(v1, v2);
	draw_it(fdf, v1, v2, yx);
/*	
	if (v1[1] < v2[1])
		y_dir = 1;
	else
		y_dir = -1;

	delta[0] = ABS(v2[0] - v1[0]);
	delta[1] = ABS(v2[1] - v1[1]);
	slope = delta[1] / delta[0];
	if (slope < 0)
		slope *= -1;
	err = slope - 0.5 * y_dir;

	x = v1[0] - 1;
	y = v1[1];
	while (++x < v2[0])
	{
		if (yx)
			mlx_pixel_put(window->mlx, window->win, y, x, 0xff);
		else
			mlx_pixel_put(window->mlx, window->win, x, y, 0xff);
		err = err + slope * y_dir;
		if (err > 0.5)
		{
			y += y_dir;
			err -= 1;
		}
	}
	*/
}
