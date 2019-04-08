
#include "libft.h"

void      *ft_memalloc(size_t size)
{
     char           *memes;
     size_t         i;

     memes = (char*)malloc(size);
     if (memes == NULL)
          return (NULL);
     i = 0;
     while (i < size)
     {
          memes[i] = 0;
          ++i;
     }
     return ((void*)memes);
}