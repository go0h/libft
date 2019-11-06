/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:18:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 19:25:29 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
