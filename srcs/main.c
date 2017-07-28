#include <stdlib.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"

void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);
char	***get_grid(char *filepath);

int		main(int argc, char **argv)
{
	//void	*mlx;
	//void	*win;
	char	***grid;
	int		i;
	int		j;

	if (argc == 2)
	{
		//mlx = mlx_init();
		//win = mlx_new_window(mlx, 400, 400, "something");
		if (!(grid = get_grid(argv[1])))
			return (0);
		i = -1;
		while (grid[++i] != (void *)0)
		{
			j = 0;
			while (grid[i][j] != (void *)0)
				ft_putendl(grid[i][j++]);
		}

		//draw_line(mlx, win, 0, 200, 400, 200);
		//mlx_loop(mlx);
	}
	return (0);
}
