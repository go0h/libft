/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:11:36 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/17 18:02:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_string.h"

/*
**	OLD IMPLEMENTATION
**size_t	ft_strlen(const char *s)
**{
**	size_t i;
**
**	i = 0;
**	while (s[i])
**		++i;
**	return (i);
**}
*/

static size_t	zero_byte(uint64_t *word)
{
	if (!(*word & 0x00000000000000ffL))
		return (0);
	else if (!(*word & 0x000000000000ff00L))
		return (1);
	else if (!(*word & 0x0000000000ff0000L))
		return (2);
	else if (!(*word & 0x00000000ff000000L))
		return (3);
	else if (!(*word & 0x000000ff00000000L))
		return (4);
	else if (!(*word & 0x0000ff0000000000L))
		return (5);
	else if (!(*word & 0x00ff000000000000L))
		return (6);
	else if (!(*word & 0xff00000000000000L))
		return (7);
	return (0);
}

size_t			ft_strlen(const char *str)
{
	uint64_t	*word;
	uint64_t	abcd;

	word = (uint64_t*)str;
	while (1)
	{
		abcd = (*word - FT_LOMAGIC) & FT_HIMAGIC;
		if (abcd && (abcd & ~(*word)))
			return (((const char*)word - str) + zero_byte(word));
		++word;
	}
	return (0);
}
