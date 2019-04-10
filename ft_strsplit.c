
#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t flag;
	size_t count;
	size_t i;

	i = 0;
	flag = 1;
	count = 0;
	while(s[i] != '\0')
	{
		if (s[i] == c && flag == 0)
			flag = 1;
		else if (s[i] != c && flag == 1)
		{
			++count;
			flag = 0;
		}
		++s;
	}
	return (count);
}

static size_t ft_strlenc(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		++i;
	return (i);
}

static void	ft_freearr(char **s)
{
	size_t i;

	i = 0;	
	while(s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	len;
	char	**arr;

	words = ft_count_words(s, c);
	if ((arr = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s == c)
			++s;
		len = ft_strlenc(s, c);
		if ((arr[i] = ft_strsub(s, 0, len)) == NULL)
		{
			ft_freearr(arr);
			return (NULL);
		}
		s += len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
