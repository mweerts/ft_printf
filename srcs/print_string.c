/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/11 14:21:51 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static	char	*get_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

static	int		ft_putstr_len(const char *str, int max)
{
	if (max != -1 && (int)ft_strlen(str) > max)
	{
		write(1, str, max);
		return (max);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int				print_string(va_list ap, t_flag *flag)
{
	char	*str;
	int		len;
	int		count;

	count = 0;
	str = get_string(ap);
	if (flag->precision != -1 && (int)ft_strlen(str) > flag->precision)
		len = flag->precision;
	else
		len = ft_strlen(str);
	if (flag->minus)
		count += ft_putstr_len(str, flag->precision);
	while (flag->width > len)
 	{
		if (flag->zero && !flag->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flag->width--;
		count++;
	}
	if (!flag->minus)
		count += ft_putstr_len(str, flag->precision);
	free(str);
	return (count);
}
