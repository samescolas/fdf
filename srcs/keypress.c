/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 12:26:37 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/03 18:22:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/ft_atexit.h"

int		keypress(int key, t_fdf	*fdf)
{
	if (key == 53)
		ft_atexit();
	else if (key == KEY_LEFT)
		fdf->rotation->y -= 0.1;
	else if (key == KEY_RIGHT)
		fdf->rotation->y += 0.1;
	else if (key == KEY_UP)
		fdf->rotation->x += 0.1;
	else if (key == KEY_DOWN)
		fdf->rotation->x -= 0.1;
	else if ((char)key == 13)
		fdf->translation->y -= 5;
	else if ((char)key == 1)
		fdf->translation->y += 5;
	else if (key == 0)
		fdf->translation->x -= 5;
	else if (key == 2)
		fdf->translation->x += 5;
	else if (key == 24)
	{
		fdf->scale->x += 0.5;
		fdf->scale->y += 0.5;
	}
	else if (key == 27)
	{
		fdf->scale->x -= 0.5;
		fdf->scale->y -= 0.5;
	}
	else if (key == 4)
		fdf->scale->z += 0.25;
	else if (key == 5)
		fdf->scale->z -= 0.25;
	else
		ft_putnbr(key);
	return (display_loop(fdf));
}
