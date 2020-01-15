/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:46:57 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/16 00:00:19 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	print_char(va_list ap, t_flag *flag)
{
	char	c;
	int		count;

	c = va_arg(ap, int);
	count = 1;
	if (flag->minus)
		ft_putchar(c);
	while (flag->width > count)
	{
		if (flag->zero && !flag->minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus)
		ft_putchar(c);
	return (count);
}
