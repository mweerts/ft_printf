/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:33:28 by mweerts           #+#    #+#             */
/*   Updated: 2020/01/05 06:01:02 by mweerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_convert	g_tab[] = {
	{'c', &get_char},
	{'s', &get_string},
	/*{'p', &convert_pointer},
	{'d', &convert_int},
	{'i', &convert_int},
	{'u', &convert_uint},
	{'x', &convert_hexamin},
	{'X', &convert_hexamaj},
	{'%', &convert_percent},*/
	{-1, NULL}};

int ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;
    int     j;

    i = 0;
    va_start(ap, str);
    
    while (str && str[i])
    {
        if (str[i] != '%')
            write(1, &str[i], 1);
        else
        {
            i++;
            j = 0;
            while (g_tab[j].c != -1)
            {
                if (g_tab[j].c == str[i])
                {
                    ft_putstr_fd(g_tab[j].function(ap), 1);
                    break ;
                }
                j++;
            }
        }
        i++;    
    }

    va_end(ap);
    return ((int)ft_strlen(str));
}