
#include <string.h>

void	  *ft_memcpy(void *dest, const void *src, size_t n)
{
	 size_t i;
	 unsigned char *dest_ch;
	 unsigned const char *src_ch;

	 dest_ch = (unsigned char*)dest;
	 src_ch = (unsigned const char*)src;
	 if (dest_ch == NULL || src_ch == NULL)
		  return (NULL);
	 i = 0;
	 while (i < n)
	 {
		  dest_ch[i] = src_ch[i];
		  ++i;
	 }
	 return (dest);
}
