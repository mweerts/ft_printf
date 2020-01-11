/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 13:04:13 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	int	ft_putstr_len(const char *str, int max)
{
	if (max != -1 && (int)ft_strlen(str) > max)
	{
		write(1, str, max);
		return (max);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	print_string(va_list ap, t_flag *flag)
{
	char	*str;
	int		len;
	int		count;

	count = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
		len = 6;
	else if (flag->precision != -1 && (int)ft_strlen(str) > flag->precision)
		len = flag->precision;
	else
		len = ft_strlen(str);
	if (flag->minus)
	{
		if (str)
			count += ft_putstr_len(str, flag->precision);
		else
			count += ft_putstr_len("(null)", flag->precision);
	}
	while (flag->width > len)
	{
		if (flag->zero && !flag->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flag->width--;
		count++;
	}
	if (!flag->minus)
	{
		if (str)
			count += ft_putstr_len(str, flag->precision);
		else
			count += ft_putstr_len("(null)", flag->precision);
	}
	return (count);
}
