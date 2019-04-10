
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	sub = ft_strnew(len + 1);
	if (sub == NULL)
		return (NULL);
	sub = ft_strncpy(sub, &s[start], len);
	return (sub);
}
