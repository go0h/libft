/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:08:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/11 21:52:38 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ch;
	unsigned const char	*src_ch;

	dest_ch = (unsigned char*)dest;
	src_ch = (unsigned const char*)src;
	i = 0;
	if (dest_ch <= src_ch || dest_ch >= (src_ch + n))
	{
		while (i < n)
		{
			dest_ch[i] = src_ch[i];
			++i;
		}
	}
	else
	{
		i = n;
		while (i--)
			dest_ch[i] = src_ch[i];
		dest_ch[i] = src_ch[i];
	}
	return ((void*)dest_ch);
}
