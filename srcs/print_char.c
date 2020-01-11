/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:46:57 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 14:34:50 by mweerts          ###   ########.fr       */
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
		write(1, &c, 1);
	while (flag->width > 1)
	{
		write(1, " ", 1);
		flag->width--;
		count++;
	}
	if (!flag->minus)
		write(1, &c, 1);
	return (count);
}
