/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 14:47:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 14:47:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	translate_object(t_fdf fdf)
{
	if (fdf.keys->w)
		fdf.translation->y -= 5;
	if (fdf.keys->a)
		fdf.translation->x -= 5;
	if (fdf.keys->s)
		fdf.translation->y += 5;
	if (fdf.keys->d)
		fdf.translation->x += 5;
}

void	scale_object(t_fdf fdf)
{
	if (fdf.keys->plus)
	{
		fdf.scale->x += 0.5;
		fdf.scale->y += 0.5;
	}
	else if (fdf.keys->minus)
	{
		fdf.scale->x -= 0.5;
		fdf.scale->y -= 0.5;
	}
	else if (fdf.keys->brack_l)
		fdf.scale->z -= 0.5;
	else if (fdf.keys->brack_r)
		fdf.scale->z += 0.5;
}

void	rotate_object(t_fdf fdf)
{
	if (fdf.keys->up)
		fdf.rotation->x += 0.1;
	else if (fdf.keys->down)
		fdf.rotation->x -= 0.1;
	if (fdf.keys->left)
		fdf.rotation->y -= 0.1;
	else if (fdf.keys->right)
		fdf.rotation->y += 0.1;
	if (fdf.keys->o)
		fdf.rotation->z -= 0.1;
	else if (fdf.keys->p)
		fdf.rotation->z += 0.1;
}

void	color_object(t_fdf *fdf)
{
	if (fdf->keys->r)
	{
		if (fdf->colors[0].r - fdf->colors[1].r > 0)
			fdf->colors[0].r -= 5;
		else
			fdf->colors[1].r -= 5;
	}
	if (fdf->keys->g)
	{
		if (fdf->colors[0].g - fdf->colors[1].g > 0)
			fdf->colors[0].g -= 5;
		else
			fdf->colors[1].g -= 5;
	}
	if (fdf->keys->b)
	{
		if (fdf->colors[0].b - fdf->colors[1].b > 0)
			fdf->colors[0].b -= 5;
		else
			fdf->colors[1].b -= 5;
	}
}
