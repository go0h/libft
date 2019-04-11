
#include "libft.h"

static size_t	ft_decn(int n)
{
	size_t i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ar;
	size_t	len;

	len = ft_decn(n);
	if (n < 0)
		len += 1;
	ar = ft_strnew(len + 1);
	--len;
	if (ar == NULL)
		return (NULL);
	if (n < 0)
		ar[0] = '-';
	while (n / 10 != 0)
	{
		ar[len] = ((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
		--len;
	}
	ar[len] = ((n % 10) < 0 ? -(n % 10) : (n % 10)) + '0';
	return (ar);

}
