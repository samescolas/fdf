#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)

# include <stdlib.h>

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
	t_keys			*keys;
	unsigned short	bp_rows;
	unsigned short	bp_cols;
}					t_fdf;

t_fdf			*fdf_init(
		unsigned short width, unsigned short height, char *title, char *filepath);
unsigned short	**read_blueprint(
		char *filepath, unsigned short *rows, unsigned short *cols);
void			fdf_destroy_later(t_fdf *fdf, int loading);

#endif
