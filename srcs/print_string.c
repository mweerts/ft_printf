/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 10:55:54 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
	count = len;
	if (flag->minus)
	{
		if (str)
			ft_putstr_fd(str, 1);
		else
			ft_putstr_fd("(null)", 1);
	}
	while (flag->width > len)
	{
		write(1, " ", 1);
		flag->width--;
		count++;
	}
	if (!flag->minus)
	{
		if (str)
			ft_putstr_fd(str, 1);
		else
			ft_putstr_fd("(null)", 1);
	}
	return (count);
}
