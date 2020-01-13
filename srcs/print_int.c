/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:45:48 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 07:55:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int print_int(va_list ap, t_flag *flag)
{
    int nbr;

    nbr = va_arg(ap, int);
    ft_putnbr_fd(nbr, 1);
    return (flag->precision);
}