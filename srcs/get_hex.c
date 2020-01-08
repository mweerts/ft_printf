/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:09 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/07 21:04:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*get_hexamaj(va_list ap)
{
	int	nbr;

	nbr = va_arg(ap, int);
	return (ft_itoahex((unsigned int)nbr, 1));
}

char	*get_hexamin(va_list ap)
{
	int	nbr;

	nbr = va_arg(ap, int);
	return (ft_itoahex((unsigned int)nbr, 0));
}
