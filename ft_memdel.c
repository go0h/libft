
#include "libft.h"

void      ft_memdel(void **ap)
{
     size_t i;

     i = 0;
     while(ap)
     {
          free(ap[i]);
          ap[i] = NULL;
          ++i;

     }
     write(1, "HERE\n", 5);
     free(ap);
     //ap = NULL;

}