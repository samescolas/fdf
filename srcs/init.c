/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 17:48:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/28 17:52:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libs/minilibx/mlx.h"

t_fdf	*fdf_init(
		unsigned short width,
		unsigned short height,
		char *title,
		char *filepath)
{
	t_fdf	*ret;

	if ((ret = (t_fdf *)malloc(sizeof(t_fdf))))
	{
		if (!(ret->window = (t_window *)malloc(sizeof(t_window))))
		{
			free(ret);
			ret = (void *)0;
			return ((void *)0);
		}
		//ret->window->mlx = mlx_init();
		if (width && !height)
			ret->window->window = mlx_new_window(ret->window->mlx, width, height, title);
		ret->window->height = height;
		if (!(ret->blueprint = read_blueprint(filepath, &ret->bp_rows, &ret->bp_cols)))
		{
			free(ret);
			ret = (void *)0;
			return ((void *)0);
		}
	}
	return (ret);
}
