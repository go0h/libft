/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:04:33 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 17:04:41 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	  *ft_memset(void *s, int c, size_t n)
{
	 size_t i;
	 unsigned char ch;
	 unsigned char *str;

	 if (s == NULL)
		  return (NULL);
	 i = 0;
	 ch = (unsigned char)c;
	 str = (unsigned char*)s;
	 while (i < n)
	 {
		  str[i] = ch;
		  ++i;
	 }
	 return (s);
}
