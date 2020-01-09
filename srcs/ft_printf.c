/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:33:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/09 01:01:05 by mweerts          ###   ########.fr       */
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

static	void	get_format(char format, va_list ap, t_flag *flag)
{
	int	i;

	i = 0;
	while (g_tab[i].c != -1)
	{
		if (g_tab[i].c == format)
			flag->str = g_tab[i].function(ap);
		i++;
	}
}

int			ft_print(const char *str, va_list ap)
{
	t_flag flag;

	flag = parse(str, ap);
	get_format(flag.format, ap, &flag);
	while (flag.width > (int)ft_strlen(flag.str))
	{
		flag.width--;
		write(1, " ", 1);
	}
	ft_putstr_fd(flag.str, 1);
	return ((int)ft_strlen(flag.str));
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str && str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			count++;
		}
		else 
		{
			i++;
			count += ft_print(&str[i], ap);
			/*if (ft_isformat(str[i]))
				ft_putstr_fd(get_format(str[i], ap), 1);*/
			
		}
		i++;
	}
	va_end(ap);
	return (count);
}
