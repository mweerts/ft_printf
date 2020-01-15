/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:42 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/15 16:23:00 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	int	put_x(void)
{
	return (ft_putstr("0x"));
}

int			print_pointer(va_list ap, t_flag *flag)
{
	char	*str;
	int		count;

	str = ft_itoahex((unsigned long long)va_arg(ap, unsigned long), 0);
	count = ft_strlen(str) + 2;
	if (flag->precision == 0 && str[0] == '0')
		count--;
	if (flag->minus)
	{
		put_x();
		if (!(flag->precision == 0 && str[0] == '0'))
			ft_putstr(str);
	}
	print_width(flag, &count);
	if (!flag->minus)
	{
		put_x();
		if (!(flag->precision == 0 && str[0] == '0'))
			ft_putstr(str);
	}
	free(str);
	return (count);
}
