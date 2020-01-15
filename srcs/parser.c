/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:24:45 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/15 15:21:04 by mweerts          ###   ########.fr       */
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
	flag->diese = 0;
	flag->str = NULL;
}

static void		parse_lh(t_flag *flag, int *i, const char *str)
{
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l')
		{
			flag->ll = 1;
			i++;
		}
		else
			flag->l = 1;
	}
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h')
		{
			flag->hh = 1;
			i++;
		}
		else
			flag->h = 1;
	}
}

static int		parse_star(t_flag *flag, va_list ap, char is_preci)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (!is_preci)
	{
		if (nbr < 0)
			flag->minus = 1;
		return (ft_abs(nbr));
	}
	else
	{
		if (nbr < 0)
			nbr = -1;
		return (nbr);
	}
}

t_flag			parse(const char *str, va_list ap, int *index)
{
	int		i;
	t_flag	flag;

	i = 0;
	init_flag(&flag);
	while (str[i] && !ft_isformat(str[i]))
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
		{
			i += ft_atoi_printf(&str[i], &flag.width) - 1;
		}
		else if (str[i] == '-')
			flag.minus = 1;
		else if (str[i] == '+')
			flag.plus = 1;
		else if (str[i] == '0')
			flag.zero = 1;
		else if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
				flag.precision = parse_star(&flag, ap, 1);
			else
				i += ft_atoi_printf(&str[i], &flag.precision) - 1;
		}
		else if (str[i] == '*')
			flag.width = parse_star(&flag, ap, 0);
		else if (str[i] == '#')
			flag.diese = 1;
		else if (str[i] == ' ')
			flag.blank = 1;
		else
			parse_lh(&flag, &i, str);
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
