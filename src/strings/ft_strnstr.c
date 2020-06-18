/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:40:55 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:12:08 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;

	if (!*haystack)
		return (NULL);
	if (!*needle)
		return ((char*)haystack);
	n = ft_strlen(needle);
	while (*haystack && n <= len--)
	{
		if (*haystack == *needle)
		{
			if (!(ft_strncmp(haystack, needle, n)))
				return ((char*)haystack);
		}
		++haystack;
	}
	return (NULL);
}
