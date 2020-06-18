/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:31:00 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 21:05:30 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = len > n ? n : len;
	ft_memcpy(dest, src, n);
	if (i < n)
		ft_memset(&dest[i], 0, n - i);
	return (dest);
}
