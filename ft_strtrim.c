
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;
	char *trim;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	j = ft_strlen(s);
	if (j != 0)
		j -= 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		--j;
	++j;
	if (i > j)
		trim = ft_strnew(1);
	else
	{
		trim = ft_strnew(j - i + 2);
		if (trim == NULL)
			return (NULL);
		trim = ft_strncpy(trim, &s[i], j - i);
	}
	return (trim);
}
