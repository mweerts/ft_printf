#include "libft.h"

int ft_putstr(char *str)
{
    if (!str)
        return (0);
    write(1, str, ft_strlen(str));
    return (ft_strlen(str));
}