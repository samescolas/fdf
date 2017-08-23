/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 15:26:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 10:58:20 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numlen(long long num, short base)
{
	short	len;

	if (num == 0)
		return (1);
	len = (num < 0);
	while (num != 0)
	{
		num /= base;
		++len;
	}
	return (len);
}
