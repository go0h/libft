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