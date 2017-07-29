/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/29 13:25:17 by sescolas         ###   ########.fr       */
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

t_fdf	*fdf_init(
		short width,
		short height,
		char *title,
		char *filepath)
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
		ft_putendl("calling read_blueprint");
		if (!(ret->blueprint = read_blueprint(filepath, &ret->bp_rows, &ret->bp_cols)))
		{
			free(ret);
			ft_fatal("err: out of memory\n");
		}
		ft_putendl("back from read_blueprint");
		ret->keys = create_keylist();
	}
	fdf_destroy_later(ret, 1);
	return (ret);
}
