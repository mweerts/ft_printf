/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:20:23 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/05 10:23:35 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(unsigned int n)
{
	int nb_char;

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

char			*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = ft_intlen(n);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i + 1] = '\0';
	if (n == 0)
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
