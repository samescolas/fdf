#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)

# include <stdlib.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_window
{
	void	*win;
	void	*mlx;
	short	height;
	short	width;
}				t_window;

typedef struct	s_keys
{
	int	up:1;
	int	down:1;
	int	left:1;
	int	right:1;
	int	escape:1;
}				t_keys;

typedef struct	s_fdf
{
	t_window	*window;
	short		**blueprint;
	t_keys		*keys;
	short		bp_rows;
	short		bp_cols;
}				t_fdf;

typedef struct	s_coord
{
	short	x;
	short	y;
	short	z;
}				t_coord;

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_point
{
	t_coord	*pos;
	t_color	*col;
}				t_point;

t_fdf		*fdf_init(short width, short height, char *title, char *fp);
short		**read_blueprint(char *filepath, short *rows, short *cols);
void		fdf_destroy_later(t_fdf *fdf, int loading);
//void		draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);
void		draw_line(t_window *window, t_point a, t_point b);

t_coord		*create_coord(short x, short y, short z);
t_point		*create_point(t_coord *coord, t_color *color);
t_color		*create_color(unsigned char r, unsigned char g, unsigned char b);
t_color		*int_to_col(int color);
int			col_to_int(t_color color);

#endif
