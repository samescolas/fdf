/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 09:49:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 15:15:38 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	assign_initial_position(t_fdf *fdf)
{
	fdf->scale = create_coord(20, 20, 1);
	fdf->translation = create_coord(600, 400, 0);
	fdf->rotation = create_coord(0.33, -0.42, -0.22);
}

void		assign_colors(t_fdf *fdf, int c1, int c2)
{
	t_color	*tmp;

	tmp = int_to_col(c1);
	fdf->colors[0] = *tmp;
	free(tmp);
	tmp = int_to_col(c2);
	fdf->colors[1] = *tmp;
	free(tmp);
	tmp = (void *)0;
}

static void	create_keys(t_fdf *fdf)
{
	t_keys	*keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		ft_fatal("err: out of memory\n");
	ft_bzero(keys, sizeof(keys));
	fdf->keys = keys;
}

static void	create_window(t_fdf *fdf, short width, short height, char *title)
{
	t_window	*window;

	if (!(window = (t_window *)malloc(sizeof(t_window))))
		ft_fatal("err: out of memory\n");
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, width, height, title);
	window->height = height;
	window->width = width;
	fdf->window = window;
}

t_fdf		*fdf_init(short width, short height, char *title, char *filepath)
{
	t_fdf	*ret;

	if ((ret = (t_fdf *)malloc(sizeof(t_fdf))))
	{
		create_window(ret, width, height, title);
		if (!(ret->blueprint = read_blueprint(
			filepath, &ret->bp_rows, &ret->bp_cols, ret->z_minmax)))
		{
			free(ret->window);
			ret->window = (void *)0;
			free(ret);
			ft_fatal("err: out of memory\n");
		}
		assign_initial_position(ret);
		assign_colors(ret, 4242, 174210);
		create_keys(ret);
	}
	fdf_destroy_later(ret, 1);
	return (ret);
}
