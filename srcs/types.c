/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:42:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/05 15:10:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coord		*create_coord(float x, float y, float z)
{
	t_coord	*ret;

	if (!(ret = (t_coord *)malloc(sizeof(t_coord))))
		ft_fatal("err: out of memory\n");
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_color		*create_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*ret;

	if (!(ret = (t_color *)malloc(sizeof(t_color))))
		ft_fatal("err: out of memory\n");
	ret->r = r;
	ret->g = g;
	ret->b = b;
	return (ret);
}

t_color		*int_to_col(int color)
{
	return (create_color(
			(color >> 16) & 0xff,
			(color >> 8) & 0xff,
			color & 0xff));
}

int			col_to_int(t_color color)
{
	int	rgb;

	rgb = color.r;
	rgb = (rgb << 8) + color.g;
	rgb = (rgb << 8) + color.b;
	return (rgb);
}
