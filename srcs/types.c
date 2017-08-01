/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 13:42:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/31 19:25:30 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libs/libft/libft.h"

t_coord		*create_coord(short x, short y, short z)
{
	t_coord	*ret;
	int		scale;

	if (!(ret = (t_coord *)malloc(sizeof(t_coord))))
		ft_fatal("err: out of memory\n");
	scale = 25;
	ret->x = x * scale;
	ret->y = y * scale;
	ret->z = z * scale;
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

t_point		*create_point(t_coord *coord, t_color *color, int scale)
{
	t_point	*ret;

	if (!(ret = (t_point *)malloc(sizeof(t_point))))
		ft_fatal("err: out of memory\n");
	ret->pos = coord;
	ret->col = color;
//	ret->px = ((float)(ret->pos->x) / MAX(ret->pos->z, 1)) * scale;
//	ret->py = ((float)(ret->pos->y) / MAX(ret->pos->z, 1)) * scale;
	if (scale)
		return (ret);
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
