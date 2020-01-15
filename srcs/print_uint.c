/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:21:19 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/15 14:00:50 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	t_number	get_number(va_list ap, t_flag *flag)
{
	t_number		number;
	long	long	nbr;

	number.len = 0;
	nbr = 0;
	if (flag->l)
		nbr = (long long)va_arg(ap, unsigned long int);
	else if (flag->ll)
		nbr = va_arg(ap, unsigned long long int);
	else if (flag->h)
		nbr = (long long)(unsigned short int)va_arg(ap, int);
	else if (flag->hh)
		nbr = (long long)(unsigned char)va_arg(ap, int);
	else
		nbr = (long long)va_arg(ap, unsigned int);
	number.sign = '+';
	ft_longlongtoa(nbr, &number, flag->precision);
	return (number);
}

int					print_uint(va_list ap, t_flag *flag)
{
	t_number	nbr;
	int			count;

	nbr = get_number(ap, flag);
	count = nbr.len;
	if (nbr.len == 1 && nbr.str[0] == '0' && flag->precision == 0)
		count = 0;
	if (flag->minus && flag->precision != 0)
		ft_putstr(nbr.str);
	while (flag->width > count)
	{
		if (flag->zero && !flag->minus && flag->precision == -1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus && flag->precision != 0)
		ft_putstr(nbr.str);
	return (count);
}
