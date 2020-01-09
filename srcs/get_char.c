/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 05:46:57 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/09 14:51:32 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*get_char(va_list ap)
{
	char	c;
	char 	*str;

	c = va_arg(ap, int);
	if (!(str = malloc(sizeof(char) * 2)))
		return (0);
	if (c == (char)0)
		str[0] = '\0';
	else
		str[0] = c;
	str[1] = '\0';
	return (str);
}
