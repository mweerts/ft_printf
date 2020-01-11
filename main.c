#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    char *str = NULL;
	int one;
	int two;

    one = ft_printf("%10s\n", NULL);
	two = printf("%10s\n", str);
	printf("Ft_printf = \t%d\nPrintf = \t%d\n", one, two);
}