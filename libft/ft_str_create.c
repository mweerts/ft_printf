/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:35:22 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/13 07:37:01 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_str_create(int c, int len)
{
    char    *str;

    if (!(str = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    ft_memset(str, c, len);
    str[len] = '\0';
    return (str);
}