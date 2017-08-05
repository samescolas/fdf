/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:26:37 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 14:52:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

static void	movement_keys(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->keys->w = 0;
	else if (key == KEY_A)
		fdf->keys->a = 0;
	else if (key == KEY_S)
		fdf->keys->s = 0;
	else if (key == KEY_D)
		fdf->keys->d = 0;
}

static void	rotation_keys(int key, t_fdf *fdf)
{
	if (key == KEY_LEFT)
		fdf->keys->left = 0;
	else if (key == KEY_RIGHT)
		fdf->keys->right = 0;
	else if (key == KEY_UP)
		fdf->keys->up = 0;
	else if (key == KEY_DOWN)
		fdf->keys->down = 0;
	else if (key == KEY_O)
		fdf->keys->o = 0;
	else if (key == KEY_P)
		fdf->keys->p = 0;
}

static void	scale_keys(int key, t_fdf *fdf)
{
	if (key == KEY_PLUS)
		fdf->keys->plus = 0;
	else if (key == KEY_MINUS)
		fdf->keys->minus = 0;
	else if (key == KEY_BRACK_L)
		fdf->keys->brack_l = 0;
	else if (key == KEY_BRACK_R)
		fdf->keys->brack_r = 0;
}

static void	color_keys(int key, t_fdf *fdf)
{
	if (key == KEY_R)
		fdf->keys->r = 0;
	else if (key == KEY_G)
		fdf->keys->g = 0;
	else if (key == KEY_B)
		fdf->keys->b = 0;
}

int			keyrelease(int key, t_fdf *fdf)
{
	if (key == KEY_ESCAPE)
		ft_atexit();
	movement_keys(key, fdf);
	rotation_keys(key, fdf);
	scale_keys(key, fdf);
	color_keys(key, fdf);
	return (0);
}
