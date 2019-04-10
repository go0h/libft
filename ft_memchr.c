/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:43:20 by astripeb          #+#    #+#             */
/*   Updated: 2019/04/09 19:44:52 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_ch;
	unsigned char	c_ch;

	s_ch = (unsigned char*)s;
	c_ch = (unsigned char)c;
	if (s_ch == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (s_ch[i] == c_ch)
			return ((void*)&s_ch[i]);
		++i;
	}
	return (NULL);
}