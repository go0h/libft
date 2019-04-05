
#include <string.h>

char *ft_strncpy(char *dest, const char *src, size_t n)
{
     size_t i;

     i = 0;
     while (i < n && src[i] != '\0')
     {
          dest[i] = src[i];
          ++i;
     }
     while (dest[i] != '\0')
     {
          dest[i] = '\0';
          ++i;
     }
     return (dest);
}