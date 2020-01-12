/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:40:43 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/12 07:21:25 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct	s_flag
{
	char	minus;
	char	plus;
	char	zero;
	int		width;
	int		precision;
	char	format;
	char	*str;
}				t_flag;

typedef	struct	s_convert
{
	char		c;
	int			(*function)(va_list ap, t_flag *flag);
}				t_convert;

int				ft_printf(const char *str, ...);
int				print_char(va_list ap, t_flag *flag);
int				print_string(va_list ap, t_flag *flag);
int				print_int(va_list ap, t_flag *flag);
char			*get_uint(va_list ap);
int				print_percent(t_flag *flag);
char			*get_hexamaj(va_list ap);
char			*get_hexamin(va_list ap);
char			*get_pointer(va_list ap);
char			*ft_itoahex(unsigned int nb, int isupper);
char			*ft_ptoahex(unsigned long nb);
int				ft_isformat(int c);
int				ft_atoi_printf(const char *str, int	*width);
t_flag			parse(const char *str, va_list ap, int	*index);
#endif
