#include <stdio.h>
#include <stdlib.h>
#include "includes/libftprintf.h"

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    int str = -10;
    t_flag test;

    test.minus = 0;
    test.zero = 0;
  //  test = parse("%-0dlol");
    ft_printf("%X%x\n", 123456789, 123456789);
	printf("%X%x\n", 123456789, 123456789);
	//ft_printf("%X\t%x\n", -42, 0);
}