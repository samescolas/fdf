/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:39:24 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/31 19:06:44 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"

float	**identity_matrix(void)
{
	float	**ret;
	int		i;

	i = 0;
	if (!(ret = (float **)malloc(4 * sizeof(float *))))
		ft_fatal("err: out of memory\n");
	while (i < 4)
	{
		if (!(ret[i] = (float *)malloc(4 * sizeof(float))))
			ft_fatal("err: out of memory\n");
		ft_bzero(ret[i], sizeof(float) * 4);
		ret[i][i] = 1;
		i += 1;
	}
	return (ret);
}

void	scale_matrix(float **mat, int axis, int scale)
{
	if (axis > 2)
		return ;
	mat[axis][axis] *= scale;
}
