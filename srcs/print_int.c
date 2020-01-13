/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:45:48 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 10:32:05 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static  int put_sign(char sign, t_flag *flag)
{
    if (sign == '-' || flag->plus)
        return(ft_putchar(sign));
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
    if (nbr.sign == '-' || flag->plus)
        count++;
  /*  if (flag->width == -1)
    {
        put_sign(nbr.sign, flag);
        put_nbr(nbr);
        return (count);
    }*/
    if (flag->minus)
    {
        put_sign(nbr.sign, flag);
        put_nbr(nbr);
    }
    while (flag->width > count)
    {
		if (flag->zero && !flag->minus)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
    }
    if (!flag->minus)
    {
        put_sign(nbr.sign, flag);
        put_nbr(nbr);
    }
    return (count);
}