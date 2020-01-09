#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    int str = 10;
    t_flag test;
	char *lol = "LOLOLOL";

    ft_printf("%*d\n", 10, str);
	printf("%*d\n", 10, str);
}