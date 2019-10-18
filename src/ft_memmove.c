/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:08:43 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/24 16:45:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_ch;
	unsigned const char	*src_ch;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ch = (unsigned char*)dest;
	src_ch = (unsigned char*)src;
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
		while (--n)
			dest_ch[n] = src_ch[n];
		dest_ch[n] = src_ch[n];
	}
	return ((void*)dest_ch);
}
