/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 12:52:26 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	int	ft_putstr_len(const char *str, int max)
{
	if (max != -1)
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

	str = va_arg(ap, char*);
	if (str == NULL)
		len = 6;
	else
		len = ft_strlen(str);
	count = 0;
	if (flag->minus)
	{
		if (str)
			count += ft_putstr_len(str, flag->precision);
		else
			count += ft_putstr_len("(null)", 6);
	}
	while (flag->width > len)
	{
		if (flag->zero)
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
			count += ft_putstr_len("(null)", 6);
	}
	return (count);
}
