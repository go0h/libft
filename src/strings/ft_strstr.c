/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:18:07 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:03:43 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int i;
	unsigned int n;

	if ((n = ft_strlen(needle)) == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			if ((ft_strncmp(&haystack[i], needle, n)) == 0)
			{
				return ((char*)&haystack[i]);
			}
		}
		++i;
	}
	return (NULL);
}
