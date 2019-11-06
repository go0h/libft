/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcredibl <pcredibl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:36:05 by astripeb          #+#    #+#             */
/*   Updated: 2019/08/28 12:30:05 by pcredibl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ch;
	unsigned const char	*src_ch;

	if (dest == src || n == 0)
		return (dest);
	dest_ch = (unsigned char*)dest;
	src_ch = (unsigned const char*)src;
	i = 0;
	while (i < n)
	{
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (dest);
}
