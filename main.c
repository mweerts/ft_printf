#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    int str = 123456;
	int one;
	int two;

    one = ft_printf("%%%10c%c\n", (char)0, 'a');
	two = printf("%%%10c%c\n", (char)0, 'a');
	printf("Ft_printf = \t%d\nPrintf = \t%d\n", one, two);
}