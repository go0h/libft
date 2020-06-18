/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:45:05 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 13:38:20 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdint.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*ptr;
	size_t	length;

	if ((ptr = ft_memchr(src, c, n)))
	{
		length = ptr - src + 1;
		ft_memcpy(dest, src, length);
		return (dest + length);
	}
	ft_memcpy(dest, src, n);
	return (NULL);
}
