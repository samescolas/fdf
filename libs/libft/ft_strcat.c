/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:33:40 by sescolas          #+#    #+#             */
/*   Updated: 2017/01/20 10:35:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*head;

	head = s1;
	while (*s1)
		++s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (head);
}
