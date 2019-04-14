
#include <limits.h>

long int		ft_atol(const char *str)
{
	long long int	nb;
	int				flag;
	
	nb = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	flag = (*str == '+' || *str == '-') ? (44 - *str++) : 1;
	while (*str > 47 && *str < 58)
	{
		nb = nb * 10 + (*str++ - '0');
		if (flag == -1 && nb < 0)
			return (LONG_MIN);
		else if (flag == 1 && nb < 0)
			return (LONG_MAX);
	}
	return (nb * flag);
}
