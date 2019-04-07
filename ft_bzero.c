
#include <string.h>

void	  ft_bzero(void *s, size_t n)
{
	 size_t i;
	 unsigned char *c;

	 i = 0;
	 c = (unsigned char*)s;
	 while (i < n)
	 {
		  c[i] = '\0';
		  ++i;
	 }
}
