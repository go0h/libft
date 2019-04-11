
#include "libft.h"

void    ft_putnbr(int n)
{
    if (n / 10 != 0)
    {
        ft_putnbr(n / 10);
    }
    if (n < 0 && (n < 0 ? -n : n) < 10)
        ft_putchar('-');
    ft_putchar(((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0');

}