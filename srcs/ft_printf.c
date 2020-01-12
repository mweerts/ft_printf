/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:33:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/12 07:04:48 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_convert	g_tab[] = {
	{'c', &print_char},
	{'s', &print_string},
	//{'p', &get_pointer},
	{'d', &print_int},
	{'i', &print_int},
	//{'u', &get_uint},
//	{'x', &get_hexamin},
	//{'X', &get_hexamaj},
	{-1, NULL}};

static	int	get_format(char format, va_list ap, t_flag *flag)
{
	int	i;

	i = 0;
	while (g_tab[i].c != -1)
	{
		if (g_tab[i].c == format)
			return (g_tab[i].function(ap, flag));
		else if (format == '%')
			return (print_percent(flag));
		i++;
	}
	return (-1);
}

static	int		ft_print_flag(const char *str, va_list ap, int	*index)
{
	t_flag	flag;
	int		count;

	count = 0;
	flag = parse(str, ap, index);
	count += get_format(flag.format, ap, &flag);
	/*while (!flag.minus && flag.width > (int)ft_strlen(flag.str))
	{
		flag.width--;
		if (flag.zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	ft_putstr_fd(flag.str, 1);
	while (flag.minus && flag.width > (int)ft_strlen(flag.str))
	{
		flag.width--;
		write(1, " ", 1);
		count++;
	}
	count += (int)ft_strlen(flag.str);*/
	return (count);
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
			count += ft_print_flag(&str[i + 1], ap, &i);	
		i++;
	}
	va_end(ap);
	return (count);
}
