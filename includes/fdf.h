#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)

void	draw_vertical_line(void *mlx, void *win, int x, int y0, int y1);
void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);

#endif
