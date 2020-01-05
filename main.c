#include <stdio.h>

int ft_printf(const char *str, ...);

int main()
{
    char *str = NULL;
    char    c;
    ft_printf("Salut%s %s %s\n", str, "LOL", "");
    printf("Salut%s %s %s\n", str, "LOL", "");
}