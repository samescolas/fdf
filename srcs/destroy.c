/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 09:10:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 17:57:24 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

static void	fdf_destroy_window(t_window *window)
{
	free(window->mlx);
	window->mlx = (void *)0;
	free(window->win);
	window->win = (void *)0;
	window->height = 0;
	window->width = 0;
	free(window);
	window = (void *)0;
}

static void	fdf_destroy_blueprint(
		short **blueprint,
		short rows,
		short cols)
{
	int		i;
	int		j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			blueprint[i][j] = 0;
		}
		free(blueprint[i]);
		blueprint[i] = (void *)0;
	}
	free(blueprint);
	blueprint = (void *)0;
}

static void	fdf_destroy(t_fdf *fdf)
{
	fdf_destroy_window(fdf->window);
	fdf_destroy_blueprint(fdf->blueprint, fdf->bp_rows, fdf->bp_cols);
	fdf->bp_rows = 0;
	fdf->bp_cols = 0;
	free(fdf);
	fdf = (void *)0;
}

void		fdf_destroy_later(t_fdf *fdf, int loading)
{
	static t_fdf	*fdf_store;

	if (loading)
	{
		if (fdf_store == (void *)0)
			fdf_store = fdf;
	}
	else
	{
		if (fdf_store != (void *)0)
			fdf_destroy(fdf_store);
	}
}
