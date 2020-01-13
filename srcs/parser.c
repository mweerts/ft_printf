/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:24:45 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 10:59:36 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->width = -1;
	flag->precision = -1;
	flag->format = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->blank = 0;
	flag->str = NULL;
}

t_flag			parse(const char *str, va_list ap, int	*index)
{
	int		i;
	t_flag	flag;

	i = 0;
	init_flag(&flag);
	while (str[i] && !ft_isformat(str[i]))
	{
		if (ft_isdigit(str[i]) && !(str[i] == '0' && ft_isdigit(str[i + 1])))
		{
			i += ft_atoi_printf(&str[i], &flag.width) - 1;
		}
		else if (str[i] == '-')
			flag.minus = 1;
		else if (str[i] == '+')
			flag.plus = 1;
		else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			flag.zero = 1;
		else if (str[i] == '*')
			flag.width = (va_arg(ap, int));
		else if (str[i] == '.')
		{
			i++;
			i += ft_atoi_printf(&str[i], &flag.precision) - 1;
		}
		else if (str[i] == ' ')
			flag.blank = 1;
		else if (str[i] == 'l')
		{
			i++;
			if (str[i] == 'l')
				flag.ll = 1;
			else
				flag.l = 1;
		}
		else if (str[i] == 'h')
		{
			i++;
			if (str[i] == 'h')
				flag.hh = 1;
			else
				flag.h = 1;
		}
		i++;
	}
	if (ft_isformat(str[i]))
	{
		flag.format = str[i];
		i++;
	}
	*index += i;
	return (flag);
}
