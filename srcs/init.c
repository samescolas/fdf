/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 09:49:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 19:19:42 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libs/libft/libft.h"
#include "../libs/minilibx/mlx.h"

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
	tmp = int_to_col(c2);
	fdf->colors[1] = *tmp;
}

t_fdf		*fdf_init(short width, short height, char *title, char *filepath)
{
	t_fdf	*ret;

	if ((ret = (t_fdf *)malloc(sizeof(t_fdf))))
	{
		if (!(ret->window = (t_window *)malloc(sizeof(t_window))))
		{
			free(ret);
			ft_fatal("err: out of memory\n");
		}
		ret->window->mlx = mlx_init();
		ret->window->win =
			mlx_new_window(ret->window->mlx, width, height, title);
		ret->window->height = height;
		ret->window->width = width;
		if (!(ret->blueprint = read_blueprint(
			filepath, &ret->bp_rows, &ret->bp_cols, ret->z_minmax)))
		{
			free(ret);
			ft_fatal("err: out of memory\n");
		}
		assign_initial_position(ret);
		assign_colors(ret, 4242, 174210);
	}
	fdf_destroy_later(ret, 1);
	return (ret);
}
