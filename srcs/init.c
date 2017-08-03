/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 09:49:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/03 15:55:30 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libs/libft/libft.h"
#include "../libs/minilibx/mlx.h"

t_keys	*create_keylist(void)
{
	t_keys	*ret;

	if (!(ret = (t_keys *)malloc(sizeof(t_keys))))
		ft_fatal("err: out of memory\n");
	return (ret);
}

t_fdf	*fdf_init(short width, short height, char *title, char *filepath)
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
		ret->window->win=
			mlx_new_window(ret->window->mlx, width, height, title);
		ret->window->height = height;
		ret->window->width = width;
		if (!(ret->blueprint =
			read_blueprint(filepath, &ret->bp_rows, &ret->bp_cols, ret->z_minmax)))
		{
			free(ret);
			ft_fatal("err: out of memory\n");
		}
		ret->keys = create_keylist();
		ret->near = 1;
		ret->far = 3;
		ret->fov = 80;
		ret->scale = create_coord(20, 20, 0.25);
		ret->translation = create_coord(150, 150, 0);
		ret->rotation = create_coord(0, 0, 0);
	}
	fdf_destroy_later(ret, 1);
	return (ret);
}
