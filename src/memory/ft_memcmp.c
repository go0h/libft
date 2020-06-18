/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:06:18 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/17 22:51:30 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ch;
	const unsigned char	*s2_ch;

	s1_ch = (const unsigned char*)s1;
	s2_ch = (const unsigned char*)s2;
	while (n--)
	{
		if (*s1_ch++ != *s2_ch++)
			return (*--s1_ch - *--s2_ch);
	}
	return (0);
}
