/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:40:43 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/05 06:02:12 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct	s_convert
{
	char		c;
	char		*(*function)(va_list ap);
}				t_convert;

int				ft_printf(const char *str, ...);
char            *get_char(va_list ap);
char            *get_string(va_list ap);
#endif
