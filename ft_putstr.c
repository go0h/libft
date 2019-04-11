
#include "libft.h"

void      ft_putstr(char const *str)
{
    while(*str)
    {
        ft_putchar(*str);
        ++str;
    }
}