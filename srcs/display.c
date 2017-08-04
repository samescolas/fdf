/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 08:43:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 12:03:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
static void	rotate_xyz2(t_fdf fdf, float v1[3], float v2[3])
{
	t_coord a;

	a = *fdf.rotation;
	v1[0] = 
}
*/

static void	rot_x(float a, float v1[3], float v2[3])
{
	v1[1] = v1[1] * cos(a) - v1[2] * sin(a);
	v1[2] = v1[1] * sin(a) + v1[2] * cos(a);

	v2[1] = v2[1] * cos(a) - v2[2] * sin(a);
	v2[2] = v2[1] * sin(a) + v2[2] * cos(a);
}

static void	rot_y(float a, float v1[3], float v2[3])
{
	v1[0] = v1[0] * cos(a) + v1[2] * sin(a);
	v1[2] = -1 * v1[0] * sin(a) + v1[2] * cos(a);

	v2[0] = v2[0] * cos(a) + v2[2] * sin(a);
	v2[2] = -1 * v2[0] * sin(a) + v2[2] * cos(a);
}
/*
static void	rot_z(float a, float v1[3], float v2[3])
{
	v1[0] = v1[0] * cos(a) - v1[1] * sin(a);
	v1[1] = v1[0] * sin(a) + v1[1] * cos(a);

	v2[0] = v2[0] * cos(a) - v2[1] * sin(a);
	v2[1] = v2[0] * sin(a) + v2[1] * cos(a);
}

static void	rotate_xyz(t_fdf fdf, float v1[3], float v2[3])
{
	t_coord	a;

	a = *fdf.rotation;
	v1[0] = v1[0] * cos(a.y) * cos(a.z) - v1[1] * cos(a.y) * sin(a.z) + v1[2] * sin(a.y);
	v1[1] = 
		v1[0] * (sin(a.x) * sin(a.y) * cos(a.z) + cos(a.x) * sin(a.z)) -
		v1[1] * (-1 * sin(a.x) * sin(a.y) * sin(a.z) + cos(a.x) * cos(a.z)) -
		v1[2] * sin(a.x) * cos(a.y);
	v1[2] =
		-1 * v1[0] * (cos(a.x) * sin(a.y) * cos(a.z) + sin(a.x) * sin(a.z))
		- v1[1] * (cos(a.x) * sin(a.y) * sin(a.z) + sin(a.x) * cos(a.z)) +
		v1[2] * cos(a.x) * cos(a.y);

	v2[0] = v2[0] * cos(a.y) * cos(a.z) - v2[1] * cos(a.y) * sin(a.z) + v2[2] * sin(a.y);
	v2[1] = 
		v2[0] * (sin(a.x) * sin(a.y) * cos(a.z) + cos(a.x) * sin(a.z)) -
		v2[1] * (-1 * sin(a.x) * sin(a.y) * sin(a.z) + cos(a.x) * cos(a.z)) -
		v2[2] * sin(a.x) * cos(a.y);
	v2[2] =
		-1 * v2[0] * (cos(a.x) * sin(a.y) * cos(a.z) + sin(a.x) * sin(a.z))
		- v2[1] * (cos(a.x) * sin(a.y) * sin(a.z) + sin(a.x) * cos(a.z)) +
		v2[2] * cos(a.x) * cos(a.y);
}
*/
static void	normalize(t_fdf fdf, float v1[3], float v2[3])
{
	v1[0] = v1[0] - fdf.bp_cols / 2 + 1;
	v1[1] = v1[1] - fdf.bp_rows / 2;
	v2[0] = v2[0] - fdf.bp_cols / 2 + 1;
	v2[1] = v2[1] - fdf.bp_rows / 2;
	v1[2] = v1[2] * fdf.scale->z;
	v2[2] = v2[2] * fdf.scale->z;

	//rotate_xyz(fdf, v1, v2);
	
	rot_x(fdf.rotation->x, v1, v2);
	rot_y(fdf.rotation->y, v1, v2);
	//rot_z(fdf.rotation->z, v1, v2);


	v1[0] = v1[0] + fdf.bp_cols / 2;
	v1[1] = v1[1] + fdf.bp_rows / 2;
	v2[0] = v2[0] + fdf.bp_cols / 2;
	v2[1] = v2[1] + fdf.bp_rows / 2;


	v1[0] = v1[0] * fdf.scale->x;
	v1[1] = v1[1] * fdf.scale->y;
	v1[2] = v1[2] * fdf.scale->z;

	v2[0] = v2[0] * fdf.scale->x;
	v2[1] = v2[1] * fdf.scale->y;
	v2[2] = v2[2] * fdf.scale->z;

	v1[0] = v1[0] + fdf.translation->x;
	v1[1] = v1[1] + fdf.translation->y;
	v1[2] = v1[2] + fdf.translation->z;
	v2[0] = v2[0] + fdf.translation->x;
	v2[1] = v2[1] + fdf.translation->y;
	v2[2] = v2[2] + fdf.translation->z;
}

static void	fill_vec(float v[3], float x, float y, float z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

void		plot_grid(t_fdf *fdf)
{
	int				row;
	int				col;
	float			v1[3];
	float			v2[3];

	row = -1;
	while (++row < fdf->bp_rows)
	{
		col = -1;
		while (++col < fdf->bp_cols - 1)
		{
			if (0 && row + 1 < fdf->bp_rows && col + 2 < fdf->bp_cols)
			{
				fill_vec(v1, col, row, fdf->blueprint[row][col]);
				fill_vec(v2, col + 1, row + 1, fdf->blueprint[row + 1][col + 1]);
				normalize(*fdf, v1, v2);
				draw_line(*fdf, v1, v2);
			}
			if (row + 1 < fdf->bp_rows)
			{
				ft_putendl("VERT");
				fill_vec(v1, col, row, fdf->blueprint[row][col]);
				fill_vec(v2, col, row + 1, fdf->blueprint[row + 1][col]);
				normalize(*fdf, v1, v2);
				draw_line(*fdf, v1, v2);
			}
			if (col + 2 < fdf->bp_cols)
			{
				ft_putendl("HORIZ");
				fill_vec(v1, col, row, fdf->blueprint[row][col]);
				fill_vec(v2, col + 1, row, fdf->blueprint[row][col + 1]);
				normalize(*fdf, v1, v2);
				draw_line(*fdf, v1, v2);
			}
		}
	}
}

int			display_loop(t_fdf *fdf)
{
	mlx_clear_window(fdf->window->mlx, fdf->window->win);
	plot_grid(fdf);
	return (0);
}
