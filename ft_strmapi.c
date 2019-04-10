
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	size_t len;
	size_t i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		++i;
	}
	return (str);
}
