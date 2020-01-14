/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 10:03:09 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/14 07:00:34 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	char	*ft_itoahex(unsigned long long nb, int isupper)
{
	char	str[24];
	char	*ret;
	int		i;
	int		j;

	i = 0;
	if (nb == 0)
		str[i++] = '0';
	while (nb != 0)
	{
		if ((nb % 16) < 10)
			str[i] = (nb % 16) + '0';
		else
			str[i] = isupper ? (nb % 16) + 'A' - 10 : (nb % 16) + 'a' - 10;
		nb /= 16;
		i++;
	}
	str[i--] = '\0';
	if (!(ret = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	j = 0;
	while (i >= 0)
		ret[j++] = str[i--];
	ret[j] = '\0';
	return (ret);
}

static	int		add_left(t_number *number, t_flag *flag)
{
	char	*str;
	int		len;

	//if (flag->precision == -1)
		//return (1);
	len = flag->precision - number->len; 
	str = NULL;
	if (len > 0)
	{
		str = ft_str_create('0', len);
		number->str = ft_strjoin_free(str, number->str);
		if (!number->str)
			return (0);
	}
/*	if (flag->diese)// && (number->str[0] != 0 && number->len != 1))
	{
		str = number->str;
		if (flag->format == 'X')
			number->str = ft_strjoin("0X", number->str);
		else if (flag->format == 'x')
			number->str = ft_strjoin("0x", number->str);
		free(str);
	}*/
	number->len = ft_strlen(number->str);
	return (1);
}

static	t_number	get_number(va_list ap, t_flag *flag)
{
	t_number					number;
	unsigned	long	long	nbr;

	if (flag->ll)
		nbr = va_arg(ap, unsigned long long int);
	else if (flag-> l)
		nbr = (unsigned long long)va_arg(ap, unsigned long int);
	else if (flag-> h)
		nbr = (unsigned long long)(unsigned short int)va_arg(ap, int);
	else if (flag-> hh)
		nbr = (unsigned long long)(unsigned char)va_arg(ap, int);
	else
		nbr = (unsigned long long)va_arg(ap, unsigned int);	
	if (flag->format == 'X')
		number.str = ft_itoahex(nbr, 1);
	else
		number.str = ft_itoahex(nbr, 0);
	
	number.len = ft_strlen(number.str);
	add_left(&number, flag);
	return(number);
}

static  int put_X(t_flag *flag)
{
    if (flag->diese)
	{
		ft_putchar('0');
		ft_putchar(flag->format);
		return (2);
	}
    return (0);
}

int	print_hex(va_list ap, t_flag *flag)
{
	int			count;
	t_number	nbr;

	nbr = get_number(ap, flag);
	count = nbr.len;
	if (nbr.len == 1 && nbr.str[0] == '0' && flag->precision == 0)
        count = 0;
	if (flag->diese)
        count += 2;
	if (flag->minus || (flag->zero && flag->precision == -1))
        put_X(flag);
	if (flag->minus && flag->precision != 0)
		ft_putstr(nbr.str);
	while (flag->width > count)
 	{
		if (flag->zero && !flag->minus && flag->precision == -1)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	if (!flag->minus)
	{	
		if (!flag->zero || (flag->zero && flag->precision != -1))
            put_X(flag);
		if (flag->precision != 0)
			ft_putstr(nbr.str);
	}
	
	return (count);
}