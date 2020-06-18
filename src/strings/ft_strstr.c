/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:18:07 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/18 22:38:07 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	size_t	len;

	if (!(n = ft_strlen(needle)))
		return ((char*)haystack);
	len = ft_strlen(haystack);
	while (*haystack && n <= len--)
	{
		if (*haystack == *needle)
		{
			if (!(ft_strncmp(haystack, needle, n)))
				return ((char*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
