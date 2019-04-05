/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:27 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/05 18:27:24 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, const char *src)
{
     size_t i;

	 i = 0;
	 while (src[i] != '\0')
     {
          dest[i] = src[i];
          ++i;
     }
     while (dest[i] != '\0')
     {
          dest[i] = '\0';
          ++i;
     }
     return (dest);
}
