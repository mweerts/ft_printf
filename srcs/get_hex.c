/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:09 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/06 05:45:31 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char    *get_hexamaj(va_list ap)
{
    return (ft_itoahex(va_arg(ap, int), 1));
}

char    *get_hexamin(va_list ap)
{
    return (ft_itoahex(va_arg(ap, int), 0));
}