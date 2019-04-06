/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 10:47:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/06 11:23:22 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *str);

size_t			ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t i;
	size_t j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	while (dst[i] != '\0')
		++i;
	j = 0;
	while (i < size)
	{
		dst[i] = src[j];
		++i;
		++j;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		++i;
	return (i);
}	
