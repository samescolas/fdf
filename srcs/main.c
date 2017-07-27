#include <stdlib.h>
#include "../libs/minilibx/mlx.h"

void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "something");

	draw_line(mlx, win, 0, 200, 400, 200);
	mlx_loop(mlx);
	return (0);
}
