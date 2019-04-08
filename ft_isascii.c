
#include "libft.h"

int	  ft_isascii(int c)
{
	 unsigned char c_ch;

	 c_ch = (unsigned char)c;
	 if (c_ch < 128)
	 {
		  return (1);
	 }
	 else
	 {
		  return (0);
	 }
}
