/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:41:05 by maxweert          #+#    #+#             */
/*   Updated: 2024/10/10 12:57:14 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_isinset(s1[i], set))
		i++;
	while (j > 0 && ft_isinset(s1[j - 1], set))
		j--;
	ret = ft_substr(s1, i, j - i);
	return (ret);
}
