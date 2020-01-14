#include "libft.h"

int ft_abs(int nb)
{
    nb = nb < 0 ? -nb : nb;
    return (nb);
}