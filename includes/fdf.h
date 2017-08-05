/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:39:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 14:58:15 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MIN(a,b) (a < b ? a : b)
# define MAX(a,b) (a > b ? a : b)
# define ABS(x) (x < 0 ? -1 * x : x)

# define KEY_ESCAPE 53
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

typedef struct		s_keys
{
	int				left:1;
	int				right:1;
	int				up:1;
	int				down:1;
	int				w:1;
	int				a:1;
	int				s:1;
	int				d:1;
	int				plus:1;
	int				minus:1;
	int				o:1;
	int				p:1;
	int				brack_l:1;
	int				brack_r:1;
	int				r:1;
	int				g:1;
	int				b:1;
}					t_keys;

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
	t_keys			*keys;
}					t_fdf;

t_fdf				*fdf_init(short width, short height, char *title, char *fp);
void				assign_colors(t_fdf *fdf, int c1, int c2);

short				**read_blueprint(
									char *filepath,
									short *rows,
									short *cols,
									short z_minmax[2]);

void				apply_rotation(t_coord *rotation, float v1[3], float v2[3]);
int					display_loop(t_fdf *fdf);
void				draw_line(t_fdf fdf, float v1[3], float v2[3]);

void				color_object(t_fdf *fdf);
void				scale_object(t_fdf fdf);
void				translate_object(t_fdf fdf);
void				rotate_object(t_fdf fdf);

int					keypress(int key, t_fdf *fdf);
int					keyrelease(int key, t_fdf *fdf);

void				fdf_destroy_later(t_fdf *fdf, int loading);

t_coord				*create_coord(float x, float y, float z);
t_color				*create_color(
						unsigned char r, unsigned char g, unsigned char b);
t_color				*int_to_col(int color);
int					col_to_int(t_color color);

#endif
