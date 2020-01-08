/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:33:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/08 22:04:46 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_convert	g_tab[] = {
	{'c', &get_char},
	{'s', &get_string},
	{'p', &get_pointer},
	{'d', &get_int},
	{'i', &get_int},
	{'u', &get_uint},
	{'x', &get_hexamin},
	{'X', &get_hexamaj},
	{'%', &get_percent},
	{-1, NULL}};

static	char	*get_format(char format, va_list ap)
{
	int	i;

	i = 0;
	while (g_tab[i].c != -1)
	{
		if (g_tab[i].c == format)
			return (g_tab[i].function(ap));
		i++;
	}
	return (ft_strdup("(null)"));
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str && str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			i++;
			ft_putstr_fd(get_format(str[i], ap), 1);
		}
		i++;
	}
	va_end(ap);
	return ((int)ft_strlen(str));
}
