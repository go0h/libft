/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:43:20 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 13:06:01 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

static inline uint64_t	haszero(uint64_t word)
{
	return ((word - FT_LOMAGIC) & ~word & FT_HIMAGIC);
}

static inline uint64_t	hasvalue(uint64_t word, uint8_t val)
{
	return (haszero(word ^ (FT_LOMAGIC * val)));
}

static void				*find_byte(const uint8_t *word, uint8_t val)
{
	if (word[0] == val)
		return ((void*)word);
	else if (word[1] == val)
		return ((void*)word + 1);
	else if (word[2] == val)
		return ((void*)word + 2);
	else if (word[3] == val)
		return ((void*)word + 3);
	else if (word[4] == val)
		return ((void*)word + 4);
	else if (word[5] == val)
		return ((void*)word + 5);
	else if (word[6] == val)
		return ((void*)word + 6);
	else if (word[7] == val)
		return ((void*)word + 7);
	return (NULL);
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	uint8_t			ch;
	uint64_t		word;
	const uint8_t	*s_byte;
	const uint64_t	*s_word;

	ch = (uint8_t)c;
	i = n / sizeof(uint64_t);
	s_word = (const uint64_t*)s;
	while (i--)
	{
		if ((word = hasvalue(*s_word, ch)))
			return (find_byte((const uint8_t*)s_word, ch));
		s_word++;
	}
	i = n % sizeof(uint64_t);
	s_byte = (const uint8_t*)s_word;
	while (i--)
	{
		if (*s_byte == ch)
			return ((void*)s_byte);
		++s_byte;
	}
	return (NULL);
}
