/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:01:50 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 14:44:03 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	print_percent(t_flag *flag)
{
	int	count;

	count = 1;
	if (flag->minus)
		write(1, "%", 1);
	while (flag->width > 1)
	{
		if (flag->zero && !flag->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flag->width--;
		count++;
	}
	if (!flag->minus)
		write(1, "%", 1);
	return (count);
}
