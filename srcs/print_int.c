/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:25:11 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/12 11:55:22 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int		ft_intlen(int n)
{	int nb_char;

	nb_char = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		nb_char++;
	}
	return (nb_char);
}

static	char	*ft_itoa_printf(int n, int precision)
{
	char	*str;
	int		is_neg;
	int		i;

	i = (ft_intlen(n) < precision) ? precision : ft_intlen(n);
	is_neg = (n < 0) ? 1 : 0;
	if (!(str = malloc(sizeof(char) * (i + is_neg + 1))))
		return (NULL);
	ft_memset(str, '0', i + is_neg);
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n = -n;
	else if (n == 0)
		str[0] = '0';
	else
		i--;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (str);
}

static	char	*get_int(va_list ap, t_flag *flag)
{
	int		nbr;

	nbr = va_arg(ap, int);
	return (ft_itoa_printf(nbr, flag->precision));
}

int				print_int(va_list ap, t_flag *flag)
{
	int 	count;
	char	*str;

	str = get_int(ap, flag);
	if (str[0] == '-')
		flag->plus = 0;
	count = ft_strlen(str) + flag->plus;
	if (flag->minus)
	{	
		if (flag->plus)
			write(1, "+", 1);
		ft_putstr_fd(str, 1);
	}
	while (flag->width > count)
 	{
		if (flag->zero && !flag->minus && flag->precision == -1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	if (!flag->minus)
	{	
		if (flag->plus)
			write(1, "+", 1);
		ft_putstr_fd(str, 1);
	}
	free(str);
	return (count);
}