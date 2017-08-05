/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:39:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 11:07:33 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)
# define ABS(x) (x < 0 ? -1 * x : x)

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PLUS 24
# define KEY_MINUS 27
# define KEY_O 31
# define KEY_P 35
# define KEY_BRACK_L 33
# define KEY_BRACK_R 30
# define KEY_R 15
# define KEY_G 5
# define KEY_B 11

# include <stdlib.h>
# include <math.h>
# include "../libs/minilibx/mlx.h"
# include "../libs/libft/libft.h"

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_window
{
	void			*win;
	void			*mlx;
	short			height;
	short			width;
}					t_window;

typedef struct		s_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_fdf
{
	t_window		*window;
	short			**blueprint;
	short			bp_rows;
	short			bp_cols;
	short			width;
	short			height;
	short			z_minmax[2];
	t_color			colors[2];
	t_coord			*scale;
	t_coord			*translation;
	t_coord			*rotation;
}					t_fdf;

t_fdf				*fdf_init(short width, short height, char *title, char *fp);
short				**read_blueprint(
				char *filepath, short *rows, short *cols, short z_minmax[2]);
void				fdf_destroy_later(t_fdf *fdf, int loading);

void				plot_grid(t_fdf *fdf);

int					keypress(int key, t_fdf *fdf);
int					display_loop(t_fdf *fdf);
void				apply_rotation(t_coord *rotation, float v1[3], float v2[3]);

void				draw_line(t_fdf fdf, float v1[3], float v2[3]);
void				assign_colors(t_fdf *fdf, int c1, int c2);

t_coord				*create_coord(float x, float y, float z);
t_color				*create_color(
						unsigned char r, unsigned char g, unsigned char b);
t_color				*int_to_col(int color);
int					col_to_int(t_color color);

#endif
