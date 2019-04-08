
#include "libft.h"

char	  *ft_strchr(const char *s, int c)
{
	 char c_ch;

	 c_ch = (char)c;
	 while (*s)
	 {
		  if (*s == c_ch)
				return ((char*)s);
		  s++;
	 }
	 return ((char*)s);
}
