#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_window
{
	void			*window;
	void			*mlx;
	unsigned short	height;
	unsigned short	width;
}					t_window;

typedef struct		s_keys
{
	unsigned int	up:1;
	unsigned int	down:1;
	unsigned int	left:1;
	unsigned int	right:1;
	unsigned int	escape:1;
}					t_keys;

typedef struct		s_fdf
{
	t_window		*window;
	unsigned short	**blueprint;
	t_keys			keys;
	unsigned short	bp_rows;
	unsigned short	bp_cols;
}					t_fdf;

void	draw_vertical_line(void *mlx, void *win, int x, int y0, int y1);
void	draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);

#endif
