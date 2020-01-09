/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:24:45 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/09 14:24:26 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->zero = 0;
	flag->width = -1;
	flag->format = 0;
	flag->str = NULL;
}

t_flag			parse(const char *str, va_list ap, int	*index)
{
	int		i;
	int		to_pass;
	t_flag	flag;

	i = 0;
	to_pass = 0;
	init_flag(&flag);
	while (str[i] && !ft_isformat(str[i]))
	{
		if (ft_isdigit(str[i]) && !(str[i] == '0' && ft_isdigit(str[i + 1])))
		{
			i += ft_atoi_printf(&str[i], &flag.width) - 1;
		}
		else if (str[i] == '-')
			flag.minus = 1;
		else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			flag.zero = 1;
		else if (str[i] == '*')
			flag.width = (va_arg(ap, int));
		i++;
	}
	if (ft_isformat(str[i]))
	{
		flag.format = str[i];
		i++;
	}
	to_pass += i;
	*index += to_pass;
	return (flag);
}
