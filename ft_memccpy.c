/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:45:05 by astripeb          #+#    #+#             */
/*   Updated: 2019/05/18 11:18:42 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_ch;
	const unsigned char	*src_ch;
	unsigned char		c_ch;

	dest_ch = (unsigned char*)dest;
	src_ch = (const unsigned char*)src;
	c_ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src_ch[i] == c_ch)
		{
			dest_ch[i] = src_ch[i];
			++i;
			return ((void*)&dest_ch[i]);
		}
		dest_ch[i] = src_ch[i];
		++i;
	}
	return (NULL);
}
