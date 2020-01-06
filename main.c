#include <stdio.h>
#include <stdlib.h>

int ft_printf(const char *str, ...);

int main(int argc, char **argv)
{
    char *x = 200000;
    ft_printf("%p\n", x);
    printf("%p\n", x);
}