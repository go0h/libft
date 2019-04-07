
#include <string.h>

char	  *ft_strchr(const char *s, int c)
{
	 int i;
	 char c_ch;

	 c_ch = (char)c;
	 i = 0;
	 if (s == NULL)
		  return (NULL);
	 while (*s)
	 {
		  if (*s == c_ch)
				return ((char*)s);
		  *s++;
	 }
	 return (NULL);
}
