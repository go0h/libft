
#include <string.h>

void	  *ft_memmove(void *dest, const void *src, size_t n)
{
	 size_t i;
	 unsigned char *dest_ch;
	 unsigned const char *src_ch;

	 dest_ch = (unsigned char*)dest;
	 src_ch = (unsigned const char*)src_ch;
	 i = 0;
	 if (dest_ch == NULL || src_ch == NULL)
		  return (NULL);
	 if (dest_ch <= src_ch || dest_ch >= (src_ch + n))
	 {
		  while(i < n)
		  {
				dest_ch[i] = src_ch[i];
				++i;
		  }
	 }
	 else
	 {
		  i = n - 1;
		  while (i >= 0)
		  {
				dest_ch[i] = src_ch[i];
				--i;
		  }
	 }
	 return (dest);
}
