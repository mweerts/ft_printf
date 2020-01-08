/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:40:43 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/08 22:00:09 by mweerts          ###   ########.fr       */
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

typedef	struct	s_flag
{
	char	minus;
	char	zero;
	int		width;
	char	*str;
}				t_flag;

int				ft_printf(const char *str, ...);
char			*get_char(va_list ap);
char			*get_string(va_list ap);
char			*get_int(va_list ap);
char			*get_uint(va_list ap);
char			*get_percent();
char			*get_hexamaj(va_list ap);
char			*get_hexamin(va_list ap);
char			*get_pointer(va_list ap);
char			*ft_itoahex(unsigned int nb, int isupper);
char			*ft_ptoahex(unsigned long nb);
int				ft_isformat(int c);
t_flag			parse(const char *str, va_list ap);
#endif
