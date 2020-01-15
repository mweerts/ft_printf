/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:45:48 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/15 18:28:57 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	t_number	get_number(va_list ap, t_flag *flag)
{
	t_number		number;
	long	long	nbr;

	number.len = 0;
	nbr = 0;
	if (flag->ll)
		nbr = va_arg(ap, long long int);
	else if (flag->hh)
		nbr = (long long)(char)va_arg(ap, int);
	else if (flag->l)
		nbr = (long long)va_arg(ap, long int);
	else if (flag->h)
		nbr = (long long)(short int)va_arg(ap, int);
	else
		nbr = (long long)va_arg(ap, int);
	number.sign = '+';
	if (nbr < 0)
	{
		nbr = -nbr;
		number.sign = '-';
	}
	ft_longlongtoa(nbr, &number, flag->precision);
	return (number);
}

static	int			put_sign(char sign, t_flag *flag)
{
	if (sign == '-' || flag->plus)
		return (ft_putchar(sign));
	if (flag->blank && sign == '+')
		return (ft_putchar(' '));
	return (0);
}

int					print_int(va_list ap, t_flag *flag)
{
	t_number	nbr;
	int			count;

	nbr = get_number(ap, flag);
	count = nbr.len;
	if (nbr.len == 1 && nbr.str[0] == '0' && flag->precision == 0)
		count = 0;
	if (nbr.sign == '-' || flag->plus || flag->blank)
		count++;
	if (flag->minus || (flag->zero && flag->precision == -1))
		put_sign(nbr.sign, flag);
	if (flag->minus && flag->precision != 0)
		ft_putstr(nbr.str);
	print_width(flag, &count);
	if (!flag->minus)
	{
		if (!flag->zero || (flag->zero && flag->precision != -1))
			put_sign(nbr.sign, flag);
		if (flag->precision != 0)
			ft_putstr(nbr.str);
	}
	free(nbr.str);
	return (count);
}
