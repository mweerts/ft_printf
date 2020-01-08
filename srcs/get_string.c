/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 06:01:34 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/07 21:04:20 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*get_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
