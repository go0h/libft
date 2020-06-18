/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:08:43 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/17 22:16:14 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	uint64_t		*d_word;
	const uint64_t	*s_word;
	uint8_t			*d_byte;
	const uint8_t	*s_byte;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest <= src || dest >= (void*)(((uint8_t*)src) + n))
		return (ft_memcpy(dest, src, n));
	else
	{
		d_word = (uint64_t*)((uint8_t*)dest + n);
		s_word = (const uint64_t*)((const uint8_t*)src + n);
		i = n / sizeof(uint64_t);
		while (i--)
			*--d_word = *--s_word;
		i = n % sizeof(uint64_t);
		d_byte = (uint8_t*)d_word;
		s_byte = (const uint8_t*)s_word;
		while (i--)
			*--d_byte = *--s_byte;
	}
	return (dest);
}
