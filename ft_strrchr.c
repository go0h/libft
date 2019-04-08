
#include "libft.h"

char	  *ft_strrchr(const char *s, int c)
{
	 int i;
	 unsigned char c_ch;
	 unsigned char *s_ch;

	 c_ch = (unsigned char)c;
	 s_ch = (unsigned char*)s;
	 i = 0;
	 if (s == NULL)
		  return (NULL);
	 while (s_ch[i] != '\0')
		  ++i;
	 while (i >= 0)
	 {
		  if (s_ch[i] == c_ch)
				return ((char*)&s_ch[i]);
		  --i;
	 }
	 return (NULL);
}
