/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/14 07:55:04 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static  int put_X()
{
	return (ft_putstr("0x"));
}

int	print_pointer(va_list ap, t_flag *flag)
{
	char	*str;
	int		count;
	flag->l = 1;
	
	str = ft_itoahex((unsigned long long)va_arg(ap, unsigned long), 0);
	count = ft_strlen(str) + 2;
	if (flag->minus && flag->precision != 0)
	{
		put_X();
		ft_putstr(str);
	}
	while (flag->width > count)
 	{
		if (flag->zero && !flag->minus && flag->precision == -1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus && flag->precision != 0)
	{
		put_X();
		ft_putstr(str);
	}
	free(str);
	return (count);
}
