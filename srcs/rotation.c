/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 17:05:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/04 19:00:22 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	v2[0] = v2[0] * cos(a) + v2[2] * sin(a);
	v1[2] = -1 * v1[0] * sin(a) + v1[2] * cos(a);
	v2[2] = -1 * v2[0] * sin(a) + v2[2] * cos(a);
}

static void	rot_z(float a, float v1[3], float v2[3])
{
	v1[0] = v1[0] * cos(a) - v1[1] * sin(a);
	v1[1] = v1[0] * sin(a) + v1[1] * cos(a);
	v2[0] = v2[0] * cos(a) - v2[1] * sin(a);
	v2[1] = v2[0] * sin(a) + v2[1] * cos(a);
}

void		apply_rotation(t_coord *rotation, float v1[3], float v2[3])
{
	rot_x(rotation->x, v1, v2);
	rot_y(rotation->y, v1, v2);
	rot_z(rotation->z, v1, v2);
}
