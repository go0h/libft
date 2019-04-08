
#include "libft.h"

void	  *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	 size_t i;
	 unsigned char *dest_ch;
	 const unsigned char *src_ch;
	 unsigned char c_ch;

	 dest_ch = (unsigned char*)dest;
	 src_ch = (const unsigned char*)src;
	 c_ch = (unsigned char)c;
	 i = 0;
	 while (i < n)
	 {
		  if (src_ch[i] == c_ch)
		  {
				dest_ch[i] = src_ch[i];
				++i;
				return ((void*)&dest_ch[i]);
		  }
		  dest_ch[i] = src_ch[i];
		  ++i;
	 }
	 return (NULL);
}
