#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
char	***get_grid(char *filepath)
{
	char	***grid;
	char	*line;
	int		rows;
	int		fd;

	if (!(grid = (char ***)malloc(100 * sizeof(char **))))
		return ((void *)0);
	if ((fd = open(filepath, O_RDONLY)) < 0)
		return ((void *)0);
	rows = -1;
	while (++rows < 100 && get_next_line(fd, &line) > 0)
		grid[rows] = ft_strsplit(line, ' ');
	return (grid);
}
