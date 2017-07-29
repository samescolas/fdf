/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:55:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/28 17:55:43 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minilibx/mlx.h"
#include "../includes/fdf.h"

void	draw_vertical_line(void *mlx, void *win, int x, int y0, int y1)
{
	int		y;

	y = y0 - 1;
	while (++y <= y1)
		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
}

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
