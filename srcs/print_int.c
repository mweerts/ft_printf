/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:25:11 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/12 07:30:12 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	char	*get_int(va_list ap)
{
	int	nbr;

	nbr = va_arg(ap, int);
	return (ft_itoa(nbr));
}

int				print_int(va_list ap, t_flag *flag)
{
	int 	count;
	char	*str;

	str = get_int(ap);
	count = ft_strlen(str);
	if (flag->plus)
	{
		write(1, "+", 1);
		count++;
	}
	if (flag->minus)
		ft_putstr_fd(str, 1);
	while (flag->width > count)
 	{
		if (flag->zero && !flag->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	if (!flag->minus)
		ft_putstr_fd(str ,1); 
	free(str);
	return (count);
}