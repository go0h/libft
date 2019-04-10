
#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char *s1u;
	unsigned char *s2u;
	size_t i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1u = (unsigned char*)s1;
	s2u = (unsigned char*)s2;
	i = 0;
	while (i < n && (s1u[i] || s2u[i]))
	{
		if (s1u[i] != s2u[i])
			return (0);
		++i;
	}
	return (1);
}
