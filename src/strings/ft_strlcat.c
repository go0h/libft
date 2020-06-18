/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:47:27 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 19:58:59 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_dst;
	size_t len_src;

	if (!size)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dst;
	while (i < (size - 1) && *src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (len_dst > size ? size + len_src : len_dst + len_src);
}
