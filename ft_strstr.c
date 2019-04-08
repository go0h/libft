/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:18:07 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/05 18:38:54 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int     ft_strncmp(const char *s1, const char *s2, unsigned int n);

static int     ft_strlen(const char *s);

char           *ft_strstr(const char *haystack, const char *needle)
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

static int     ft_strncmp(const char *s1, const char *s2, unsigned int n)
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
