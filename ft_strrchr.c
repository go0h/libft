
#include <string.h>

char	  *ft_strrchr(const char *s, int c)
{
	 int i;
	 char c_ch;

	 c_ch = (char)c;
	 i = 0;
	 if (s == NULL)
		  return (NULL);
	 while (s[i] != '\0')
		  ++i;
	 while (i >= 0)
	 {
		  if (s[i] == c_ch)
				return ((char*)&s[i]);
		  --i;
	 }
	 return (NULL);
}
