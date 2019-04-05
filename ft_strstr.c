
#include <string.h>
#include <stdio.h>

static int     ft_strncmp(const char *s1, const char *s2, unsigned int n);

static int     ft_strlen(const char *s);

char           *ft_strstr(const char *haystack, const char *needle)
{
     unsigned int i;
     unsigned int n;

     n = ft_strlen(needle);
     i = 0;
     while (haystack[i] != '\0')
     {
          if (haystack[i] == needle[0])
          {
               if ((ft_strncmp(&haystack[i], needle, n)) == 0)
               {
                    return ((char*)&haystack[i]);
               }
          }
          ++i;
     }
     return (NULL);
}

static int     ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

static int     ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}