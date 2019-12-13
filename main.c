#include <stdio.h>
#include "libftprintf.h"

int main()
{
    int i;
    int j;
    unsigned int l = 4294967295;

    char c = 'l';
	j = ft_printf("%u\n", l);
    printf("%d", j);

}
