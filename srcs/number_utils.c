/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 08:23:07 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 13:36:28 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static  int		longlong_len(long long nbr)
{
    int count;

    count = 0;
    if (nbr == 0)
        return (1);
    while (nbr != 0)
    {
        nbr = nbr / 10;
        count++;
    }
    return (count);
}

int	ft_longlongtoa(long long nbr, t_number	*number, int precision)
{
	char	*str;
	int		i;

    number->len = longlong_len(nbr);
	if (number->len < precision)
		number->len = precision;
    i = number->len;
	if(!(str = ft_str_create('0', number->len)))
		return (0);
	str[i--] = '\0';
    if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	number->str = str;
	return (1);
}
