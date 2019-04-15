
#include "libft.h"

void	ft_del_mem(void *data, size_t size)
{
	size *= 0;
	if (data)
		free(data);
	data = NULL;
}
