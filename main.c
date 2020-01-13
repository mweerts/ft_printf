#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    void *str = NULL;
	int one;
	int two;

	one = ft_printf("%10.5d\n%-10.5d\n", 123, -123);
	two = printf("%10.5d\n%-10.5d\n", 123, -123);
    printf("Ft_printf = \t%d\nPrintf = \t%d\n", one, two);
   //printf("%s", ft_str_create('a', 3));
}