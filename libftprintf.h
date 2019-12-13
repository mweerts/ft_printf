/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:14:55 by mweerts           #+#    #+#             */
/*   Updated: 2019/12/13 07:51:52 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int     ft_printf(const char *str, ...);
void    parse_flags(const char *str, va_list ap);
void    ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int n);
void    ft_putstr(char *s);
size_t  ft_strlen(const char *s);

#endif
