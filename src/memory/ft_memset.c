/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:04:33 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/17 20:36:53 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	uint8_t		ch;
	uint64_t	word;
	uint64_t	*w_ptr;
	uint8_t		*c_ptr;

	ch = (uint8_t)c;
	word = (uint64_t)ch * FT_LOMAGIC;
	w_ptr = (uint64_t*)s;
	i = n / sizeof(uint64_t);
	while (i--)
		*w_ptr++ = word;
	c_ptr = (uint8_t*)w_ptr;
	i = n % sizeof(uint64_t);
	while (i--)
		*c_ptr++ = ch;
	return (s);
}
