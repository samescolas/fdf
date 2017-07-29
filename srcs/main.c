/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/28 17:17:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

void			draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1);
unsigned short	**read_bp(char *filepath, unsigned short *rows, unsigned short *cols);

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
		if (!(ret->blueprint = read_bp(filepath, &ret->bp_rows, &ret->bp_cols)))
		{
			free(ret);
			ret = (void *)0;
			return ((void *)0);
		}
	}
	return (ret);
}

int		main(int argc, char **argv)
{
	//void	*mlx;
	//void	*win;
	t_fdf			*fdf;
	unsigned short	**grid;
	int				i;
	int				j;

	if (argc == 2)
	{
		//mlx = mlx_init();
		//win = mlx_new_window(mlx, 400, 400, "something");
		if (!(fdf = fdf_init(400, 400, "Testing...", argv[1])))
			return (0);
		i = -1;
		grid = fdf->blueprint;
		while (++i < fdf->bp_rows)
		{
			j = -1;
			ft_putstr("[");
			while (++j < fdf->bp_cols)
			{
				if (grid[i][j] <= 9 && j > 0)
					write(1, " ", 1);
				if (j > 0)
					write(1, " ", 1);
				ft_putnbr(grid[i][j]);
			}
			ft_putendl("]");
		}
		//draw_line(mlx, win, 0, 200, 400, 200);
		//mlx_loop(mlx);
	}
	return (0);
}
