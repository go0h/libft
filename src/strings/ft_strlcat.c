/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:47:27 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:02:33 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t i;
	size_t j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	i = len_dst;
	j = 0;
	while (i < (size - 1) && src[j])
		dst[i++] = src[j++];
	while (i < size)
	{
		dst[i] = '\0';
		++i;
	}
	if (len_dst > size)
		return (size + len_src);
	return (len_dst + len_src);
}