/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:38:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/28 17:52:34 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libs/minilibx/mlx.h"
#include "../libs/libft/libft.h"
#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_fdf			*fdf;
	unsigned short	**grid;
	int				i;
	int				j;

	if (argc == 2)
	{
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
		//mlx_loop(mlx);
	}
	return (0);
}
