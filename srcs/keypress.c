/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:26:37 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 11:06:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

void	translate_object(int key, t_coord *translation)
{
	if (key == KEY_W)
		translation->y -= 10;
	else if (key == KEY_A)
		translation->x -= 10;
	else if (key == KEY_S)
		translation->y += 10;
	else if (key == KEY_D)
		translation->x += 10;
}

void	scale_object(int key, t_coord *scale)
{
	if (key == KEY_PLUS)
	{
		scale->x += 0.5;
		scale->y += 0.5;
	}
	else if (key == KEY_MINUS)
	{
		scale->x -= 0.5;
		scale->y -= 0.5;
	}
	else if (key == KEY_BRACK_L)
		scale->z -= 0.5;
	else if (key == KEY_BRACK_R)
		scale->z += 0.5;
}

void	rotate_object(int key, t_coord *rotation)
{
	if (key == KEY_UP)
		rotation->x += 0.25;
	else if (key == KEY_DOWN)
		rotation->x -= 0.25;
	else if (key == KEY_LEFT)
		rotation->y -= 0.25;
	else if (key == KEY_RIGHT)
		rotation->y += 0.25;
	else if (key == KEY_O)
		rotation->z -= 0.25;
	else if (key == KEY_P)
		rotation->z += 0.25;
}

void	color_object(int key, t_color *colors)
{
	if (key == KEY_R)
	{
		if (colors[0].r - colors[1].r > 0)
			colors[0].r -= 5;
		else
			colors[1].r -= 5;
	}
	else if (key == KEY_G)
	{
		if (colors[0].g - colors[1].g > 0)
			colors[0].g -= 5;
		else
			colors[1].g -= 5;
	}
	else if (key == KEY_B)
	{
		if (colors[0].b - colors[1].b > 0)
			colors[0].b -= 5;
		else
			colors[1].b -= 5;
	}
}

int		keypress(int key, t_fdf *fdf)
{
	if (key == 53)
		ft_atexit();
	else
		ft_putnbr(key);
	scale_object(key, fdf->scale);
	translate_object(key, fdf->translation);
	rotate_object(key, fdf->rotation);
	color_object(key, fdf->colors);
	return (display_loop(fdf));
}
