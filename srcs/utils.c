/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:52:33 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/08 23:12:38 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_isformat(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
	{
		return (1);
	}
	return (0);
}

char	*ft_itoahex(unsigned int nb, int isupper)
{
	char	str[9];
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

char	*ft_ptoahex(unsigned long nb)
{
	char	str[19];
	char	*ret;
	int		i;
	int		j;

	i = 0;
	if (nb == 0)
		str[i++] = '0';
	while (nb != 0)
	{
		str[i] = (nb % 16) < 10 ? (nb % 16) + '0' : (nb % 16) + 'a' - 10;
		nb /= 16;
		i++;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = '\0';
	if (!(ret = malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	j = 0;
	while (i >= 0)
		ret[j++] = str[i--];
	ret[j] = '\0';
	return (ret);
}
