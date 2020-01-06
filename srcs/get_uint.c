/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:21:19 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/05 10:22:18 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char    *get_uint(va_list ap)
{
    unsigned int nbr;

    nbr = va_arg(ap, int);
    return (ft_uitoa(nbr));
}