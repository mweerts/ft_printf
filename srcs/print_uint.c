/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:21:19 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 13:31:27 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	print_uint(va_list ap, t_flag *flag)
{
	unsigned int	nbr;

	flag->precision = 1;
	nbr = va_arg(ap, unsigned int);
	return (ft_putstr(ft_uitoa(nbr)));
}
