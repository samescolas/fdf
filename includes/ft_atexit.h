/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 14:11:17 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/28 14:11:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATEXIT_H
# define FT_ATEXIT_H

# define STRING_BUFFER 5
# define FUNCTION_BUFFER 5

typedef void	(*t_void_func_ptr)(void);

void	ft_str_atexit(int loading, char *str_to_free);
void	ft_func_atexit(int loading, void (*func_to_load)(void));
void	ft_atexit(void);

#endif
