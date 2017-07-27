#include "../libs/minilibx/mlx.h"

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
	derr = (y1 - y0) / (x1 - x0);
	err = derr - 0.5;

	y = y0;
	x = x0 - 1;

	color = 0x00FFFFFF;
	pixel_count = 0;
	while (++x < x1)
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
