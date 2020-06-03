/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:28:31 by astripeb          #+#    #+#             */
/*   Updated: 2020/06/02 19:01:04 by astripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_ch;
	unsigned char	*s_ch;
	unsigned int	i;

	i = 0;
	c_ch = (unsigned char)c;
	s_ch = (unsigned char*)s;
	while (s_ch[i])
	{
		if (s_ch[i] == c_ch)
			return ((char*)&s_ch[i]);
		i++;
	}
	if (s_ch[i] == c_ch)
		return ((char*)&s_ch[i]);
	else
		return (NULL);
}
