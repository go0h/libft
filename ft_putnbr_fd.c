
#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n / 10 != 0)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    if (n < 0 && (n < 0 ? -(n) : n) < 10)
        ft_putchar_fd('-', fd);
    ft_putchar_fd(((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0', fd);

}