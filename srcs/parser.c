/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 08:24:45 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/06 11:52:28 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static  void    init_flag(t_flag *flag)
{
    flag->minus = 0;
    flag->zero = 0;
    flag->width = -1;
}

t_flag  parse(const char *str, va_list ap)
{
    int i;
    t_flag flag;

    i = 0;
    init_flag(&flag);
    while (str[i] && !ft_isformat(str[i]))
    {
        if (str[i] == '-')
            flag.minus = 1;
        else if (str[i] == '0' && !ft_isdigit(str[i - 1]))
            flag.zero = 1;
        else if (str[i] == '*')
            flag.zero = (va_arg(ap, int));
        i++ ;
    }
    return (flag);\
}