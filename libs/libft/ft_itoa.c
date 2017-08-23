/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:19:38 by sescolas          #+#    #+#             */
/*   Updated: 2017/08/07 11:02:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long long n, short base, char base_case)
{
	char	*bkwds_num;
	char	*head;
	int		sign;

	bkwds_num = ft_strnew(ft_numlen(n, base));
	if (!bkwds_num)
		return (NULL);
	head = bkwds_num;
	sign = (n < 0 ? -1 : 1);
	n *= sign;
	while (n >= base)
	{
		if (n % base < 10)
			*bkwds_num++ = (n % base) + '0';
		else
			*bkwds_num++ = (n % base) - 10 + base_case;
		n /= base;
	}
	if (n < 10)
		*bkwds_num++ = n + '0';
	else
		*bkwds_num++ = n - 10 + base_case;
	*bkwds_num = (sign == -1 ? '-' : '\0');
	return (ft_strrev(head));
}
