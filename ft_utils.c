/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 03:01:29 by maxweert          #+#    #+#             */
/*   Updated: 2024/10/30 00:15:30 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int nargs, ...)
{
	int		max;
	int		curr;
	int		i;
	va_list	ap;

	va_start(ap, nargs);
	i = 0;
	max = INT_MIN;
	while (i < nargs)
	{
		curr = va_arg(ap, int);
		if (curr > max)
			max = curr;
		i++;
	}
	return (max);
}

void	ft_swap(char *a, char *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
