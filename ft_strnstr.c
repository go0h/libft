/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:40:55 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/05 21:48:23 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int     ft_strncmp(const char *s1, const char *s2, size_t len);

static int     ft_strlen(const char *s);

char           *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
     unsigned int i;
     unsigned int n;

	 if (haystack == NULL || (n = ft_strlen(needle)) == 0)
		 return ((char*)haystack);
	 i = 0;
	 while (haystack[i] != '\0' && i < len)
     {
		 if (haystack[i] == needle[0] && (i + n) < len)
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

static int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static int     ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}
