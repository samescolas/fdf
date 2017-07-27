#include <stdlib.h>
#include "../libs/minilibx/mlx.h"

void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);

int		main(void)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "something");

	draw_line(mlx, win, 0, 147, 50, 400);
	mlx_loop(mlx);
	return (0);
}

void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1)
{
	long long	color;
	float		dx;
	float		dy;
	float		derr;
	float		err;
	int			y;
	int			x;
	int			pixel_count;

	dx = x1 - x0;
	dy = y1 - y0;
	derr = dx / dy;
	err = derr - 0.5;

	y = y0;
	x = x0 - 1;

	color = 0x00FFFFFF;
	pixel_count = 0;
	while (++x < x1)
	{
		if (pixel_count > 50)
			color -= 174;
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
