/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:52:33 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/06 05:53:52 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char    *ft_itoahex(unsigned int nb, int isupper)
{
	char	str[8];
	char	*ret;
	int		i;
	int		j;

	i = 0;
	if (nb == 0)
	{
		str[0] = '0';
		i++;
	}
	while (nb != 0)
	{
		if ((nb % 16) < 10)
			str[i] = (nb % 16) + '0';
		else if (isupper != 0)
			str[i] = (nb % 16) + 'A' - 10;
        else
            str[i] = (nb % 16) + 'a' - 10;
        
		nb /= 16;
		i++;
	}
	str[i] = '\0';
	j = (int)ft_strlen(str) - 1;
	if (!(ret = malloc(sizeof(char) * j)))
		return (NULL);
	i = 0;
	while (str[i])
		ret[j--] = str[i++];
	return (ret);
}

char    *ft_ptoahex(unsigned long nb)
{
	char	str[18];
	char	*ret;
	int		i;
	int		j;

	i = 0;
	if (nb == 0)
	{
		str[0] = '0';
		i++;
	}
	while (nb != 0)
	{
		if ((nb % 16) < 10)
			str[i] = (nb % 16) + '0';
        else
            str[i] = (nb % 16) + 'a' - 10;
        
		nb /= 16;
		i++;
	}
    str[i++] = 'x';
    str[i++] = '0';
	str[i] = '\0';
	j = (int)ft_strlen(str) - 1;
	if (!(ret = malloc(sizeof(char) * j)))
		return (NULL);
	i = 0;
	while (str[i])
		ret[j--] = str[i++];
	return (ret);
}