
#include <string.h>

char *ft_strcpy(char *dest, const char *src)
{
     size_t i;

     i = 0;
     while (src[i] != '\0')
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