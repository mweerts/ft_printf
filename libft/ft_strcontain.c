/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:05:03 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/15 17:07:47 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcontain(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	if (set == NULL)
		return (1);
	while (s1 && s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				return (1);
		}
	}
	return (0);
}
