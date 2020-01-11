#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    char *str = NULL;
	int one;
	int two;

    one = ft_printf("%.5s\n", "tubular");
	two = printf("%.5s\n", "tubular");
	printf("Ft_printf = \t%d\nPrintf = \t%d\n", one, two);
}