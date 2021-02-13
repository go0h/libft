/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:43:45 by astripeb          #+#    #+#             */
/*   Updated: 2021/02/13 19:13:18 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char	*res;

	if (!new_size)
	{
		free(ptr);
		return (0);
	}
	if (!(res = (char*)ft_memalloc(new_size)))
		return (NULL);
	ft_memcpy(res, ptr, old_size > new_size ? new_size : old_size);
	ft_memdel(&ptr);
	return (res);
}
