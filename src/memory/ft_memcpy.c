/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:36:05 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/17 21:40:01 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	uint64_t		*d_word;
	const uint64_t	*s_word;
	uint8_t			*d_byte;
	const uint8_t	*s_byte;

	if (!n || dest == src)
		return (dest);
	d_word = (uint64_t*)dest;
	s_word = (const uint64_t*)src;
	i = n / sizeof(uint64_t);
	while (i--)
		*d_word++ = *s_word++;
	d_byte = (uint8_t*)d_word;
	s_byte = (const uint8_t*)s_word;
	i = n % sizeof(uint64_t);
	while (i--)
		*d_byte++ = *s_byte++;
	return (dest);
}
