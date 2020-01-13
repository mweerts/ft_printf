/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:45:48 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 12:08:15 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static  int put_sign(char sign, t_flag *flag)
{
    if (sign == '-' || flag->plus)
        return(ft_putchar(sign));
    if (flag->blank && sign == '+')
        return (ft_putchar(' '));
    return (0);
}

/*int put_left(t_flag *flag)
{

}
Printf =        6

int put_right(t_flag *flag)
{

}*/

static  int put_nbr(t_number number)
{
    /*static int count;

    count = 0;
    if (nbr > 9)
        put_nbr(nbr / 10, flag);
    count += ft_putchar((nbr % 10) + '0');*/
    return (ft_putstr(number.str));
}

int print_int(va_list ap, t_flag *flag)
{
    t_number    nbr;
    int         count;

    nbr = get_number(ap, flag);
    count = nbr.len;
    if (nbr.len == 1 && nbr.str[0] == '0' && flag->precision == 0)
        count = 0;
    if (nbr.sign == '-' || flag->plus || flag->blank)
        count++;
    if (flag->minus || (flag->zero && flag->precision == -1))
        put_sign(nbr.sign, flag);
    if (flag->minus && flag->precision != 0)
        put_nbr(nbr);
    while (flag->width > count)
    {
		if (flag->zero && !flag->minus &&flag->precision == -1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
    }
    if (!flag->minus)
    {
        if (!flag->zero || (flag->zero && flag->precision != -1))
            put_sign(nbr.sign, flag);
        if (flag->precision != 0)
            put_nbr(nbr);
    }
    return (count);
}